#include <iostream>

struct NIL {
	typedef NIL Head;
	typedef NIL Tail;
};

template<typename H, typename T = NIL>
struct LIST {
	typedef H Head;
	typedef T Tail;
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
struct position {
	static const bool found = eq<element, typename T::Head>::result;
	static const int result = found ? 0 : 1 + position<element, typename T::Tail>::result;
};

template<typename element>
struct position<element, NIL> {
	static const int result = 0;
};

template<typename T>
struct Instance {
	typename T::Head element;
	Instance<typename T::Tail> next;
};

template<>
struct Instance<NIL> {};

template<typename T, int N>
struct Nth {
	typedef typename Nth<typename T::Tail, N - 1>::result result;
};

template<typename T>
struct Nth<T, 0> {
	typename T::Head result;
};

template<typename T, int N>
struct NthInstance {
	typedef typename NthInstance<typename T::Tail, N - 1>::NthInstanceType NthInstanceType;
	template<typename InsList>
	static NthInstanceType& get(InsList& ilist) {
		return NthInstance<typename T::Tail, N - 1>::get(ilist.next);
	}
};

template<typename T>
struct NthInstance<T, 0> {
	typedef typename T::Head NthInstanceType;
	template<typename InsList>
	static NthInstanceType& get(InsList& ilist) {
		return ilist.element;
	}
};

class Facade {
private:
	typedef LIST<int, LIST<char, LIST<float> > > m_list;
	Instance<m_list> m_instance;
public:
	template<typename PK>
	int find(PK) {
		return position<PK, m_list>::result;
	}

	template<typename PK>
	typename NthInstance<m_list, position<PK, m_list>::result>::NthInstanceType& get_instance(PK) {
		const int idx_position = position<PK, m_list>::result;
		typedef typename NthInstance<m_list, idx_position>::NthInstanceType idx_type;
		idx_type& idx = NthInstance<m_list, idx_position>::get(m_instance);
		return idx;
	}
};

int main(int argc, char** argv) {
	
	Facade f;
	int &a = f.get_instance(1);
	char &b = f.get_instance('a');
	float &c = f.get_instance(1.0f);
	a = 42; b = 'n'; c = 4.2f;
	std::cout << f.get_instance(1) << "\n";
	std::cout << f.get_instance('a') << "\n";
	std::cout << f.get_instance(1.0f) << "\n";
	a = 43; b = 'm'; c = 5.2f;
	std::cout << f.get_instance(1) << "\n";
	std::cout << f.get_instance('a') << "\n";
	std::cout << f.get_instance(1.0f) << "\n";	

	return 0;
}
