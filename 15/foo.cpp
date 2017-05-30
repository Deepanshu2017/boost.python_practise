#include <boost/python.hpp>
#include <string>

namespace entity {
  struct Entity {
  public:
    Entity(const int id, const std::string& name): id_(id), name_(name) {}
    const int id_;
    std::string name_;
  };
}

namespace matrix {
  struct Matrix : public entity::Entity {
  public:
    Matrix(unsigned int x, unsigned int y, int id, const std::string& name) : entity::Entity(id, name),
      size_x_(x), size_y_(y) {}
    unsigned int size_x() const { return size_x_; }
    unsigned int size_y() const { return size_y_; }

  private:
    unsigned int size_x_;
    unsigned int size_y_;
  };
}

BOOST_PYTHON_MODULE(foo) {
  boost::python::class_<entity::Entity>("Entity", boost::python::init<int, const std::string&>())
    .def_readonly("id", &entity::Entity::id_)
    .def_readwrite("name", &entity::Entity::name_)
    ;

  boost::python::class_<matrix::Matrix,
			boost::python::bases<entity::Entity> >("Matrix",
							       boost::python::init<unsigned int, unsigned int, int, const std::string&>())
    .def("size_x", &matrix::Matrix::size_x)
    .def("size_y", &matrix::Matrix::size_y)
    ;
}
