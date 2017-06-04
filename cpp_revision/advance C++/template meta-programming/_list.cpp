#include <iostream>

struct assertion { };

template<bool cond, typename T = assertion>
struct assert {
	typedef typename T::Fail check;
};

template<>
struct assert<true> {
	typedef void check;
};

template<int T>
struct Data {
	static const int result = T;
};

struct Nil {
	typedef Nil Head;
	typedef Nil Tail;
};

template<typename H, typename T = Nil>
struct List {
	typedef H Head;
	typedef T Tail;
};

template<typename T>
struct Len {
	static const unsigned result = 1 + Len<typename T::Tail>::result;
};

template<>
struct Len<Nil> {
	static const unsigned result = 0;
};

template<typename T, unsigned N>
struct _N_Len {
	typedef typename _N_Len<typename T::Tail, N - 1>::result result;
};

template<typename T>
struct _N_Len<T, 0> {
	typedef typename T::Head result;
};

template<typename T, unsigned N>
struct N_Len {
	typedef typename assert<(Len<T>::result > N)>::check temp;
	typedef typename _N_Len<T, N>::result result;
};

template<typename element, typename T>
struct prepand {
	typedef List<element, T> result;
};

template<typename element, typename T>
struct _append {
	typedef typename _append<element, typename T::Tail>::result next;
	typedef List<typename T::Head, next> result;
};

template<typename element>
struct _append<element, Nil> {
	typedef List<element> result;
};

template<typename element, typename T = Nil>
struct append {
	typedef typename _append<element, T>::result result;
};

template<typename X, typename Y>
struct eq {
	static const bool result = false;
};

template<typename X>
struct eq<X, X> {
	static const bool result = true;
};

template<typename element, typename T>
struct contains {
	static const bool result = eq<element, typename T::Head>::result || \
							   contains<element, typename T::Tail>::result;
};

template<typename element>
struct contains<element, Nil> {
	static const bool result = false;
};

template<typename element, typename T>
struct _position {
	static const bool found = eq<element, typename T::Head>::result;
	static const unsigned result = found ? 0 : 1 + _position<element, typename T::Tail>::result;
};

template<typename element>
struct _position<element, Nil> {
	static const unsigned result = 0;
};

template<typename element, typename T>
struct position {
	typedef typename assert<(contains<element, T>::result)>::check temp;
	static const unsigned result = _position<element, T>::result;
};

class Facade {
public:

	template<class PK>
	int find(PK) {
		return position<PK, mylst>::result;
	}

private:
	typedef List<int, List<char, List<float> > > mylst;
};

template<typename T>
struct Instance {
	typename T::Head instance;
	Instance<typename T::Tail> next;
};

template<>
struct Instance<Nil> { };

int main(int argc, char** argv) {
	
	typedef List<Data<1>, List<Data<2>, List<Data<3>, List<Data<4> > > > > lst;
	std::cout << "lenght is: " << Len<lst>::result << '\n';
	std::cout << "element is: " << N_Len<lst, 1>::result::result << '\n';
	// std::cout << "element is: " << N_Len<lst, 6>::result::result << '\n';
	// above line should cause the assertion to fail

	typedef prepand<Data<0>, lst>::result lst2;
	// std::cout << "lenght is: " << Len<lst2>::result << '\n';
	// std::cout << "element is: " << N_Len<lst2, 1>::result::result << '\n';

	typedef append<Data<5>, lst2>::result lst3;
	// std::cout << "length is: " << Len<lst3>::result << '\n';
	
	typedef append<Data<1> >::result lst4;
	// std::cout << "lenght is: " << Len<lst4>::result << '\n';
	// std::cout << std::boolalpha << contains<Data<1>, lst3>::result << '\n';

	std::cout << position<Data<5>, lst3>::result << '\n';

	Facade f;
	std::cout << f.find(1) << '\n';
	std::cout << f.find('a') << '\n';
	std::cout << f.find(1.0f) << '\n';

	typedef List<int, List<char, List<float> > > tlist;
	Instance<tlist> ins;
	ins.instance = 1;
	ins.next.instance = 'a';
	ins.next.next.instance = 1.0f;
	std::cout << ins.next.instance << '\n';
	
	return 0;
}
