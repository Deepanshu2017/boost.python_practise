#include <iostream>
#include <boost/python.hpp>

template<typename T>
class Base {
public:
  void process() {
    std::cout << "Process" << std::endl;
    static_cast<T*>(this)->work();
  }
};

class Derived1 : public Base<Derived1> {
public:
  Derived1() {
    std::cout << "Derived 1" << std::endl;
  }
  void work() {
    std::cout << "Work of derived 1" << std::endl;
  }
};

class Derived2 : public Base<Derived2> {
public:
  Derived2() {
    std::cout << "Derived 2" << std::endl;
  }
  void work() {
    std::cout << "Work of derived 2" << std::endl;
  }
};

void export_to_python() {
  namespace py = boost::python;

  py::class_<Derived2>("Derived2", py::init<>())
    .def("proc", &Derived2::process)
    ;
  
  py::class_<Derived1>("Derived1", py::init<>())
    .def("proc", &Derived1::process)
    ;
}

BOOST_PYTHON_MODULE(foo) {
  export_to_python();
}
