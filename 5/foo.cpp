#include <string>
#include <boost/python.hpp>

std::string call(const std::string& name) {
	return "Hello, " + name;
}

BOOST_PYTHON_MODULE(foo) {
  boost::python::def("call", call);
}
