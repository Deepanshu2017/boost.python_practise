
#include <boost/python.hpp>
#include <fstream>

void init() {
  std::ofstream ofs("foobar.txt");
  ofs << "Init has been called";
}

BOOST_PYTHON_MODULE(module_init) {
  init();
}
