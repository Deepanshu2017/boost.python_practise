#include <boost/python.hpp>
#include <string>

namespace data_members {
  struct Identifiable {
  public:
    Identifiable(const int id, const std::string& name) : id_(id), name_(name) {}
    const int id_;
    std::string name_;
  };
}

BOOST_PYTHON_MODULE(foo) {
  boost::python::class_<data_members::Identifiable>("Identifiable", boost::python::init<int, const std::string&>())
    .def_readonly("id", &data_members::Identifiable::id_)
    .def_readwrite("name", &data_members::Identifiable::name_)
    ;
}
