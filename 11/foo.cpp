#include <boost/python.hpp>

namespace matrix {
  class Matrix {
  public:
    Matrix(const Matrix& m) : size_x_(m.size_x()), size_y_(m.size_y()) {}
    Matrix(unsigned int x, unsigned int y = 100) : size_x_(x), size_y_(y) {}
    // Matrix(unsigned int x) : size_x_(x), size_y_(10) {}
    unsigned int size_x() const { return size_x_; }
    unsigned int size_y() const { return size_y_; }

  private:
    unsigned int size_x_;
    unsigned int size_y_;
  };
}


BOOST_PYTHON_MODULE(foo) {
  boost::python::class_<matrix::Matrix>("Matrix", boost::python::init<const matrix::Matrix&>())
    .def(boost::python::init<unsigned int, boost::python::optional<unsigned int> >())
    // .def(boost::python::init<unsigned int>())
    .def("size_x", &matrix::Matrix::size_x)
    .def("size_y", &matrix::Matrix::size_y)
    ;
}
