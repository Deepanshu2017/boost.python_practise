#include <iostream>

template<int egg, int floor>
struct solve;

template<int current_floor, int egg, int floor>
struct loop {
	static const bool stop = current_floor > floor;
	static const int r1 = stop ? 0 : solve<egg - 1, current_floor - 1>::result;
	static const int r2 = stop ? 0 : solve<egg, floor - current_floor>::result;
	static const int local = stop ? 0 : ((r1 > r2 ? r1 : r2) < (loop<current_floor + 1, egg, floor>::local) ? (loop<current_floor + 1, egg, floor>::local) : (r1 > r2 ? r1 : r2));
};

template<int current_floor, int egg>
struct loop<current_floor, current_floor, egg> {
	static const bool stop = current_floor > current_floor;
	static const int r1 = stop ? 0 : solve<egg - 1, current_floor - 1>::result;
	static const int r2 = stop ? 0 : solve<egg, current_floor - current_floor>::result;
	static const int local = stop ? 0 : (r1 > r2 ? r1 : r2);
};

template<int egg, int floor>
struct solve {
	static const int result = 1 + loop<1, egg, floor>::local;
};

template<>
struct solve<1, 0> {
	static const int result = 0;
};

//No floor left
template<int egg>
struct solve<egg, 0> {
	static const int result = 0;
};

// If you have 1 egg left
template<int floor>
struct solve<1, floor> {
	static const int result = floor;
};

int main(int argc, char** argv) {

	std::cout << "result is: " << solve<2, 9>::result << std::endl;

	return 0;
}
