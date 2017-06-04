#include <type_traits>
#include <typeinfo>
#include <iostream>
#include <string>

template <typename T>
std::string expression_name() {
    typedef typename std::remove_reference<T>::type TR;
    std::string r = typeid(TR).name();
    if (std::is_const<TR>::value)
        r += "const ";
    if (std::is_volatile<TR>::value)
        r += "volatile ";
    if (std::is_lvalue_reference<T>::value)
        r = "lvalue expression of type " + r;
    else if (std::is_rvalue_reference<T>::value)
        r = "xvalue expression of type " + r;
    else
        r = "prvalue expression of type " + r;
    return r;
}

class Foo {
public:
  explicit Foo(int x) : data(x) {};

  Foo& operator++() {
      data += 1;
      return *this;
    }

  void* get_addr() {
      return (void*)this;
    }

  friend Foo operator+ (const Foo& lhs, const Foo& rhs);
  friend std::ostream& operator<< (std::ostream& os, const Foo& f);

private:
  int data;
};

std::ostream& operator<< (std::ostream& os, const Foo& f) {
  return (os << f.data);
}

Foo operator+ (const Foo& lhs, const Foo& rhs) {
  return Foo(lhs.data + rhs.data);
}

void bar(Foo& f) {
  std::cout << "bar(l-value ref)" << std::endl;
}

void bar(const Foo& f) {
  std::cout << "bar(const l-value ref)" << std::endl;
}

void bar(Foo&& f) {
  std::cout << "bar(r-value ref)" << std::endl;
}


int main(void) {
    std::cout << "Foo(5) is a " << expression_name<decltype(Foo(5))>() << '\n';
    std::cout << "Foo(5).get_addr() is a " << expression_name<decltype(Foo(5).get_addr())>() << '\n';
    std::cout << "Foo(78) = Foo(86) is a " << expression_name<decltype(Foo(78) = Foo(86))>() << '\n';
    std::cout << "++Foo(5) is a " << expression_name<decltype(++Foo(5))>() << '\n';
    std::cout << "++(Foo(78) + Foo(86)) is a " << expression_name<decltype(++(Foo(78) + Foo(86)))>() << '\n';
    std::cout << "Foo(78) + Foo(86) is a " << expression_name<decltype(Foo(78) + Foo(86))>() << '\n';
    std::cout << "std::move(Foo(5)) is a " << expression_name<decltype(std::move(Foo(5)))>() << '\n';
    std::cout << "std::move(++Foo(5)) is a " << expression_name<decltype(std::move(++Foo(5)))>() << '\n';
    return 0;
}
