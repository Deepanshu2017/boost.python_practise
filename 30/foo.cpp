#include <boost/python.hpp>
#include <iostream>
#include <string>


template<class X, class Y, int Z>
struct foo {
  foo(X a, Y b, int c=10) : a_(a), b_(b) {
    if (c_ < c) c_ = c;
  };
  void prt() { std::cout << "a: " << a_ << " b: " << b_ << " c: " << c_ << std::endl; }
  /*
  // For method 1
  void add0(X a, Y b) {
    a_ += a;
    b_ += b;
  }
  void add1(X a, Y b, int c) {
    a_ += a;
    b_ += b;
    c_ += c;
  }
  */
  void add(X a, Y b, int c=0) {
    a_ += a;
    b_ += b;
    c_ += c;
  }
private:
  X a_;
  Y b_;
  int c_ = Z;
};

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(add_overloads, add, 2, 3)


template<class X, class Y, int Z>
void export_foo(std::string name1) {
  boost::python::class_<foo<X, Y, Z>>(name1.c_str(), boost::python::init<X, Y, boost::python::optional<int>>())
    .def("prt", &foo<X, Y, Z>::prt)
    /*
    // For method 1
    .def("add", &foo<X, Y, Z>::add0)
    .def("add", &foo<X, Y, Z>::add1)
    */
    .def("add", &foo<X, Y, Z>::add, add_overloads())
    ;
}

BOOST_PYTHON_MODULE(foo) {
  export_foo<int, int, 10>("foo_int");
  export_foo<std::string, std::string, 10>("foo_string");
  export_foo<double, double, 10>("foo_double");
}
