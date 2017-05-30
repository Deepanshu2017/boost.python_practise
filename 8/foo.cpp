#include <boost/python.hpp>

double volume(double a, double b, double c) { return a * b * c; }
double volume(double a, double b, double c, double d) { return a * b * c * d; }
double volume(double a, double b, double c, double d, double e) { return a * b * c * d * e; }

double (*volume3)(double, double, double) = &volume;
double (*volume4)(double, double, double, double) = &volume;
double (*volume5)(double, double, double, double, double) = &volume;

BOOST_PYTHON_MODULE(foo) {
  boost::python::def("vol", volume3);
  boost::python::def("vol", volume4);
  boost::python::def("vol", volume5);
}
