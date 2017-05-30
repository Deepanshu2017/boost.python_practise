#include <iostream>
#include <boost/python.hpp>

std::string f(int x = 10) {
  std::cout << "in default args " << 10 << std::endl;
  return "True";
}

std::string f0() {
  std::cout << "Calling default from wrapper" << std::endl;
  return f();
}

double test(double a=1, double b=2, double c=3) {
  return a * b * c;
}

BOOST_PYTHON_FUNCTION_OVERLOADS(test_over, test, 0, 3);

BOOST_PYTHON_MODULE(foo) {
  boost::python::def("c", f);
  boost::python::def("c", f0);
  boost::python::def("d", test, test_over());
}
