#include <boost/python.hpp>

class MyException : public std::exception {};

void throw_exception() { throw MyException(); }

void my_excp(const MyException& m) {
  PyErr_SetString(PyExc_SystemError, "Failed due to system error");
}

BOOST_PYTHON_MODULE(foo) {
  boost::python::register_exception_translator<MyException>(my_excp);
  boost::python::def("t", &throw_exception);
}
