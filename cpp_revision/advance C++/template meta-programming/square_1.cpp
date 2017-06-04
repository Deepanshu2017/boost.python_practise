#include <iostream>

template<int num, int num_2>
struct greater {
	static const bool result = num < num_2;
};

template<bool var1, bool var2>
struct IF {
	static const bool result = var2;
};

template<bool var2>
struct IF<true, var2> {
	static const bool result = true;
};
template<int num, int val>
struct is_square;

template<int num>
struct square {
	static const bool result = is_square<num, 1>::result;
};

template<>
struct square<1> {
	static const bool result = true;
};

template<int num, int val>
struct is_square {
	static const bool result = IF<num == val*val, IF<greater<num, val>::result, is_square<num, val + 1>::result>::result>::result;
};

template<int num>
struct is_square<num, num> {
	static const bool result = false;
};

int main(int argc, char** argv) {

	static_assert(square<1>::result, "Not a square");
	static_assert(square<4>::result, "Not a square");
	static_assert(square<9>::result, "Not a square");

	return 0;
}
