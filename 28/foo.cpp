#include <boost/python.hpp>
#include <iostream>
#include <string>


template<class T>
struct foo {
  foo(T a) : a_(a) {};
  void prt() { std::cout << a_ << std::endl; }
private:
  T a_;
};


template<class T>
void export_foo(std::string name) {
  boost::python::class_<foo<T>>(name.c_str(), boost::python::init<T>())
    .def("prt", &foo<T>::prt);
}

BOOST_PYTHON_MODULE(foo) {
  export_foo<int>("foo_int");
  export_foo<std::string>("foo_string");
  export_foo<double>("foo_double");
}
