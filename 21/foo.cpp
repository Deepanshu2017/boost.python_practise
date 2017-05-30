#include <boost/python.hpp>
#include <string>
#include <iostream>

struct Coordinate {
  Coordinate(long xin, long yin, long zin): x(xin), y(yin), z(zin) {}
  long x;
  long y;
  long z;
  void prt() {
    std::cout << x << " " << y << " " << z << std::endl;
  }
};


//Convert a C++ object into python object
struct CoordinateToTuple {
  static PyObject* convert(const Coordinate& c) {
    return boost::python::incref<>(boost::python::make_tuple(c.x, c.y, c.z).ptr());
  }
};


//Convert a Python object into C++ object
static void* convertible(PyObject* obj_ptr) {
  // Check if py_obj is convertable to cpp_obj or not
  if (!PyTuple_Check(obj_ptr)) return 0;
  if (PyTuple_Size(obj_ptr) != 3) return 0;
  if (!PyNumber_Check(PyTuple_GetItem(obj_ptr, 0))) return 0;
  if (!PyNumber_Check(PyTuple_GetItem(obj_ptr, 1))) return 0;
  if (!PyNumber_Check(PyTuple_GetItem(obj_ptr, 2))) return 0;

  return obj_ptr;
}


static void construct(PyObject* obj_ptr, boost::python::converter::rvalue_from_python_stage1_data* data) {
  // Extract data
  long x_cord = PyLong_AsLong(PyNumber_Long(PyTuple_GetItem(obj_ptr, 0)));
  long y_cord = PyLong_AsLong(PyNumber_Long(PyTuple_GetItem(obj_ptr, 1)));
  long z_cord = PyLong_AsLong(PyNumber_Long(PyTuple_GetItem(obj_ptr, 2)));

  //Grab pointer to memory into which to construct the new cpp object
  void* storage = ((boost::python::converter::rvalue_from_python_storage<Coordinate> *)data)->storage.bytes;

  //In-place construction of cpp_obj
  new(storage) Coordinate(x_cord, y_cord, z_cord);

  //Stash the memory chunk pointer for later use by boost.python
  data->convertible = storage;
}


Coordinate cor_to_tup() {
  Coordinate c(5, 6, 7);
  return c;
}


void tup_to_cor(Coordinate c) {
  c.prt();
}

BOOST_PYTHON_MODULE(foo) {
  boost::python::to_python_converter<Coordinate, CoordinateToTuple>();
  boost::python::def("get", &cor_to_tup);
  
  boost::python::converter::registry::push_back(&convertible, &construct, boost::python::type_id<Coordinate>());
  boost::python::def("set", &tup_to_cor);
}
