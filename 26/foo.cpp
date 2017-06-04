#include <utility>  // std::pair
#include <typeinfo> // typeid
#include <boost/python.hpp>
#include <iostream>

template<typename X, typename Y>
class BaseFunction {
public:
  static void export_BaseFunction() {
    // If type is already registered, then return early.
    namespace python = boost::python;

    bool is_registered = (0 != python::converter::registry::query(python::type_id<BaseFunction>())->to_python_target_type());

    if (is_registered)
      return;

    // Otherwise, register the type as an internal type.
    std::string type_name = std::string("_") + typeid(BaseFunction).name();
    std::cout << type_name << " here" << std::endl;
    python::class_<BaseFunction>(type_name.c_str(), python::no_init);
  };
};

class Function
  : public BaseFunction<std::pair<double, double>, double>
{
private:

  typedef BaseFunction<std::pair<double, double>, double> parent_type;

public:

  static void export_Function()
  {
    // Explicitly register parent.
    parent_type::export_BaseFunction();
    // Expose this type and its relationship with parent.
    boost::python::class_<Function, boost::python::bases<parent_type>,
        boost::shared_ptr<Function> >("Function");
  }
};

/// @brief Example function to demonstrate upcasting.
void spam(BaseFunction<std::pair<double, double>, double>&) {}

BOOST_PYTHON_MODULE(foo)
{
  Function::export_Function();
  boost::python::def("spam", &spam);
}
