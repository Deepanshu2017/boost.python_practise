#include <boost/python.hpp>
#include <iostream>
#include <string>


template<class X, class Y>
struct foo {
  foo(X a, Y b) : a_(a), b_(b) {};
  void prt() { std::cout << a_ << " " << b_ << std::endl; }
  void add(X a, Y b) {
    a_ += a;
    b_ += b;
  }
private:
  X a_;
  Y b_;
};


template<class X, class Y>
void export_foo(std::string name) {
  boost::python::class_<foo<X, Y>>(name.c_str(), boost::python::init<X, Y>())
    .def("prt", &foo<X, Y>::prt)
    .def("add", &foo<X, Y>::add)
    ;
}

BOOST_PYTHON_MODULE(foo) {
  export_foo<int, int>("foo_int");
  export_foo<std::string, std::string>("foo_string");
  export_foo<double, double>("foo_double");
}
