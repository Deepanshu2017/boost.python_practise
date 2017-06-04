#include <iostream>
using namespace std;

class BoVector {
private:
  double* arr_;
public:
  int size;

  BoVector() {
    std::cout << "default" << std::endl;
    size = 100;
    arr_ = new double[size];
    for (auto i = 0; i < size; ++i)
      arr_[i] = i * i;
  }
  
  BoVector(const BoVector& rhs) {
    size = rhs.size;
    arr_ = new double[size];
    for (auto i = 0; i < size; ++i) {
      arr_[i] = rhs.arr_[i];
    }
    std::cout << "copy constructor" << std::endl;
  }

  BoVector(BoVector&& rhs) {
    size = rhs.size;
    arr_ = rhs.arr_;
    rhs.arr_ = nullptr;
    std::cout << "move constructor" << std::endl;
  }
  
  ~BoVector() {
    std::cout << "deleted" << std::endl;
    delete[] arr_;
  }
};

void foo(BoVector v) {
  std::cout << v.size << " in foo" << std::endl;
}

BoVector getBoVector() {
  BoVector b;
  b.size = 20;
  return b;
}


int main() {
  foo(move(getBoVector()));
}
