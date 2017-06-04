#include <iostream>

template<int Egg, int Floor>
struct Solve;

template<int Egg, int Floor, typename = std::make_sequence<Floor> >
struct SolveImpl;

template<int a, int b>
struct max {
	static const int value = a > b ? a : b;
};

template<int Egg, int Floor, size_t ... Current>
struct SolveImpl<Egg, Floor, std::index_sequence<Current...> > {
	using type = add1< min< max< Solve<Egg - 1, Current>, Solve<Egg, Floor - Current - 1> ... > > >;
};

template<int Egg, int Floor>
struct Solve : std::conditional_t< (Floor == 0 || Floor == 1 || Egg == 1), int_<Floor>, SolveImpl<Egg, Floor> >::type {};
