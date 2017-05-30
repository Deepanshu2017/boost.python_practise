#include <boost/python.hpp>

namespace matrix {
  class Matrix {};
}

BOOST_PYTHON_MODULE(foo) {
  boost::python::class_<matrix::Matrix>("Matrix");
}
