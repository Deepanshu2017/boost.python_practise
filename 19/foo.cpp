#include <boost/python.hpp>
#include <string>

struct Coordinate {
  Coordinate(long xin, long yin, long zin): x(xin), y(yin), z(zin) {}
  long x;
  long y;
  long z;
};

struct CoordinateToTuple {
  static PyObject* convert(const Coordinate& c) {
    return boost::python::incref<>(boost::python::make_tuple(c.x, c.y, c.z).ptr());
  }
};

Coordinate get() {
  Coordinate c(5, 6, 7);
  return c;
}

BOOST_PYTHON_MODULE(foo) {
  boost::python::to_python_converter<Coordinate, CoordinateToTuple>();
  boost::python::def("get", &get);
}
