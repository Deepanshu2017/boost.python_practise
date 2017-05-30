#include <boost/python.hpp>
#include <string>

namespace matrix {
  class Matrix {
  public:
    Matrix(unsigned int x, unsigned int y): size_x_(x), size_y_(y) {}
    unsigned int size_x() const { return size_x_; }
    unsigned int size_y() const { return this->size_y_; }
  private:
    unsigned int size_x_;
    unsigned int size_y_;
  };

  Matrix makeSquareMatrix(unsigned int size) { return Matrix(size, size); }
  bool isSquare(const Matrix& m) { return m.size_x() == m.size_y(); }
}

BOOST_PYTHON_MODULE(foo) {
  boost::python::class_<matrix::Matrix>("Matrix", boost::python::init<unsigned int, unsigned int>())
    .def("size_x", &matrix::Matrix::size_x)
    .def("size_y", &matrix::Matrix::size_y)
    ;

  boost::python::def("make_square_matrix", matrix::makeSquareMatrix);
  boost::python::def("is_square", matrix::isSquare);
}
