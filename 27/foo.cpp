//https://stackoverflow.com/questions/24568501/exposing-c-functions-that-return-pointer-using-boost-python
#include <boost/python.hpp>

/// Legacy API.
int* make_int() { return new int(42); }

/// Auxiliary function that adapts the legacy API to Python.
int py_make_int() {
  std::auto_ptr<int> ptr(make_int());
  return *ptr;
}

/// Auxiliary class that adapts the legacy API to Python.
class holder : private boost::noncopyable {
public:
  holder() : value_(make_int()) {}
  int get_value() const     { return *value_; }
  void set_value(int value) { *value_ = value; }

private:
  std::auto_ptr<int> value_;
};

/// Factory function for the holder class.
holder* make_holder() {
  return new holder();
}

BOOST_PYTHON_MODULE(foo) {
  namespace python = boost::python;

  python::def("make_int", &py_make_int);

  python::class_<holder, boost::noncopyable>("Holder", python::no_init)
    .add_property("value", python::make_function(&holder::get_value), python::make_function(&holder::set_value))
    ;

  python::def("make_holder", &make_holder, python::return_value_policy<python::manage_new_object>());
}
