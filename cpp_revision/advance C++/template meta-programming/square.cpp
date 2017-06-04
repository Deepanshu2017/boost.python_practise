#include <iostream>

template<bool Conditon, bool Then, bool Else>
struct IF {
	static const bool result = Then;
};
template<bool Then, bool Else>
struct IF<false, Then, Else> {
	static const bool result = Else;
};

template<int num, int num_2>
struct greater {
	static const bool result = num > num_2;
};

template<int num, int num_2>
struct _square {
	static const bool result = IF
				< num == num_2 * num_2,
				  true,
				  IF <
						greater<num, num_2>::result, 
				        _square<num, num_2 + 1>::result,
						false
					 >::result
				>::result;
};

template<int num>
struct square {
	static const bool result = _square<num, 1>::result;
};

template<int num>
struct _square<num, num> {
	static const bool result = false;
};

template<>
struct square<1> {
	static const bool result = true;
};

int main(int argc, char** argv) {

	static_assert(square<4>::result, "square");
	static_assert(square<5>::result, "square");

	return 0;
}
