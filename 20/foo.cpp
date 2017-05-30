#include <boost/python.hpp>
#include <iostream>

struct Coordinate {
  Coordinate(long xin, long yin, long zin) : x(xin), y(yin), z(zin) {}
  long x;
  long y;
  long z;
  void prt() {
    std::cout << x << " " << y << " " << z << std::endl;
  }
};

static void* convertible(PyObject* obj_ptr) {
  if (!PyTuple_Check(obj_ptr)) return 0;
  if (PyTuple_Size(obj_ptr) != 3) return 0;
  if (!PyNumber_Check(PyTuple_GetItem(obj_ptr, 0))) return 0;
  if (!PyNumber_Check(PyTuple_GetItem(obj_ptr, 1))) return 0;
  if (!PyNumber_Check(PyTuple_GetItem(obj_ptr, 2))) return 0;

  return obj_ptr;
}

static void construct(PyObject* obj_ptr, boost::python::converter::rvalue_from_python_stage1_data* data) {
  long x_cord = PyLong_AsLong(PyNumber_Long(PyTuple_GetItem(obj_ptr, 0)));
  long y_cord = PyLong_AsLong(PyNumber_Long(PyTuple_GetItem(obj_ptr, 1)));
  long z_cord = PyLong_AsLong(PyNumber_Long(PyTuple_GetItem(obj_ptr, 2)));
  void* storage = ((boost::python::converter::rvalue_from_python_storage<Coordinate> *)data)->storage.bytes;
  new(storage) Coordinate(x_cord, y_cord, z_cord);
  data->convertible = storage;
}

void get(Coordinate c) {
  c.prt();
}

BOOST_PYTHON_MODULE(foo) {
  boost::python::converter::registry::push_back(&convertible, &construct, boost::python::type_id<Coordinate>());
  boost::python::def("c", &get);
}
