#include <iostream>
#include <typeinfo>

template<typename T>
struct identify {
	using type = T;
};

class Foo {};

int main(int argc, char** argv) {

	using t = typename identify<int>::type;
	using t_2 = typename identify<char>::type;
	using t_3 = typename identify<Foo>::type;
	std::cout << typeid(t).name() << std::endl;
	std::cout << typeid(t_2).name() << std::endl;
	std::cout << typeid(t_3).name() << std::endl;

	return 0;
}
