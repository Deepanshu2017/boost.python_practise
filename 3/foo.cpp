#include <string>
#include <boost/python.hpp>

int cpp_fun(const std::string& c) {
  return c.size();
}

BOOST_PYTHON_MODULE(foo) {
  boost::python::def("python_name", cpp_fun);
}
