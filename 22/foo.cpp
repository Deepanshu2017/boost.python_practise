#include <boost/python.hpp>
#include <iostream>

class Base {
public:
  virtual int f(int x) const = 0;
};

int runBase(const Base& b, int x) {
  return b.f(x);
}

class BaseWrapper : public Base, public boost::python::wrapper<Base> {
public:
  int f(int x) const {
    return this->get_override("f")(x);
  }
};

BOOST_PYTHON_MODULE(foo) {
  boost::python::def("run_base", &runBase);
  boost::python::class_<BaseWrapper, boost::noncopyable>("Base", boost::python::init<>())
    .def("f", &BaseWrapper::f)
    ;
}

/*
in python
import foo
class A(foo.Base):
  def f(self, x):
    return 42 * x

print(foo.run_base(A(), 5)
*/
