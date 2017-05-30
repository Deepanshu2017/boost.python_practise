#include <boost/python.hpp>
#include <iostream>

struct MyException : public std::exception {};

void throw_exception() { throw MyException(); }

void throw_exception_with_message() {
  try {
    throw_exception();
  } catch (const MyException& m) {
    //PyErr_Print();
    PyErr_SetString(PyExc_SystemError, "Caught a MyException Error...not sure what to do!");
    boost::python::throw_error_already_set();
  }
}

BOOST_PYTHON_MODULE(foo) {
  boost::python::def("throw_excp", &throw_exception_with_message);
}
