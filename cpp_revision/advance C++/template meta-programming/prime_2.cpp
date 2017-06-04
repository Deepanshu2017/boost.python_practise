#include <iostream>
#include <vector>
std::vector<int> prime_holder;

template<int p, int i>
struct is_prime {
	static const bool prime = ((p % i) && is_prime<p, i - 1>::prime);
};

template<int p>
struct is_prime<p, 1> {
	static const bool prime = true;
};

template<int i>
struct prime_print {
	prime_print<i - 1> p;
	static const bool prime = is_prime<i, i - 1>::prime;
	void foo() {
		p.foo();
		if(prime) 
			prime_holder.push_back(i);
	}
};

template<>
struct prime_print<1> {
	static const bool prime = false;
	void foo() {}
};

#ifndef PRIME
#define PRIME 300
#endif

int main(int argc, char** argv) {

	prime_print<PRIME> p;
	p.foo();
	for(auto i : prime_holder)
		std::cout << i << '\n';

	return 0;
}
