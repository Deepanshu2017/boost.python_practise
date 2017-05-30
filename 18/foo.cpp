#include <boost/python.hpp>

int expensive_computation(int x, int factor) {
  return x * factor;
}

boost::python::list run(boost::python::list values, int factor) {
  boost::python::list ret;
  for (int idx = 0; idx < boost::python::len(values); ++idx) {
    int val = boost::python::extract<int>(values[idx]);
    ret.append(boost::python::make_tuple(val, expensive_computation(val, factor)));
  }
  return ret;
}

BOOST_PYTHON_MODULE(foo) {
  boost::python::def("run", &run);
}
