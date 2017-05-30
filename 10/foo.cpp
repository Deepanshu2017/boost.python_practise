#include <boost/python.hpp>

namespace matrix {
  class Matrix {
  public:
    Matrix(): size_x_(0), size_y_(0) {}
    unsigned int size_x() const { return size_x_; }
    unsigned int size_y() { return size_y_; }

  private:
    unsigned int size_x_, size_y_;
  };
}

class Matrix2 {};

BOOST_PYTHON_MODULE(foo) {
  boost::python::class_<matrix::Matrix>("Matrix")
    .def("size_x", &matrix::Matrix::size_x)
    .def("size_y", &matrix::Matrix::size_y)
    ;
  boost::python::class_<Matrix2>("Matrix2");
}
