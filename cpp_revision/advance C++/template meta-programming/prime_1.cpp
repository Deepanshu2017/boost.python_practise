#include <iostream>

template<int p, int i>
struct is_prime {
	static const int prime = ((p % i) && is_prime<p, i - 1>::prime);
};

template<int p>
struct is_prime<p, 1> {
	static const int prime = p;
};

template<int i>
struct prime_print {
	prime_print<i - 1> p;
	static const int prime = is_prime<i, i - 1>::prime;
	void f() {
		p.f();
		if(prime) {
			std::cout << "prime number: " << i << std::endl;
		}
	}
};

template<>
struct prime_print<1> {
	static const int prime = 0;
	void f() { }
};

int main(int argc, char** argv) {
	
	prime_print<2000> a;
	a.f();

	return 0;
}
