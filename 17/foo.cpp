#include <boost/python.hpp>

enum Days {
  Sunday,
  Monday,
  Tuesday,
  Wednesday,
  Thursday = 8,
  Friday,
  Saturday
};

BOOST_PYTHON_MODULE(foo) {
  boost::python::enum_<Days>("Days")
    .value("Sunday", Sunday)
    .value("Monday", Monday)
    .value("Tuesday", Tuesday)
    .value("Wednesday", Wednesday)
    .value("Thursday", Thursday)
    .value("Friday", Friday)
    .value("Saturday", Saturday)
    ;
}
