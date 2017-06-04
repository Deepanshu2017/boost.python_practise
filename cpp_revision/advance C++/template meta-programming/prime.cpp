#include <iostream>

template <int p, int i>
struct is_prime {
	enum { prim = ( (p % i) && is_prime<p, i - 1>::prim ) }; 
}; 

template <int p>
struct is_prime<p, 1> {
	enum { prim = 1 };
}; 

template <int i>
struct Prime_print {      // primary template for loop to print prime numbers
	Prime_print<i - 1> a; 
	enum { prim = is_prime<i, i - 1>::prim };
	void f() {
		a.f();
		if (prim) {
			std::cout << "prime number:" << i << std::endl;
		}
	} 
}; 

template<>
struct Prime_print<1> {   // full specialization to end the loop
	enum { prim = 0 };
	void f() {}
}; 


#ifndef LAST 
#define LAST 18 
#endif

int main(void) {
   Prime_print<LAST> a; 
   a.f(); 
}
