#include <boost/python.hpp>
#include <string>
#include <iostream>

namespace entity {
  class Entity {
  public:
    Entity(int id, const std::string& name): id_(id), name_(name) {}
    int id() { return id_; }
    std::string name() { return name_; }
    void set_name(const std::string& name) { name_ = name; }
    void print() { std::cout << "Working!" << std::endl; }
  private:
    int id_;
    std::string name_;
  };
}

BOOST_PYTHON_MODULE(foo) {
  boost::python::class_<entity::Entity>("Entity", boost::python::init<int, const std::string&>())
    .add_property("id", &entity::Entity::id)
    .add_property("name", &entity::Entity::name, &entity::Entity::set_name)
    .def("prt", &entity::Entity::print)
    ;
}
