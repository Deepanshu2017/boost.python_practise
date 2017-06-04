#include <iostream>
#include <cstdio>
typedef long long ll;

template<ll x, ll y>
struct fraction {
	static const ll num = x;
	static const ll den = y;
};

template<ll x>
struct factorial {
	static const ll result = x * factorial<x - 1LL>::result;
};

template<>
struct factorial<0> {
	static const ll result = 1LL;
};

template<ll x, ll y>
struct GCD {
	static const ll result = GCD<y, x % y>::result;
};

template<ll x>
struct GCD<x, 0> {
	static const ll result = x;
};

template<typename frac>
struct simplify {
	static const ll gcd = GCD<frac::num, frac::den>::result;
	typedef fraction<frac::num / gcd, frac::den / gcd> result;
};

template<ll x, typename frac>
struct scalarMultiply {
	typedef fraction<frac::num * x, frac::den> result;
};

template<typename frac1, typename frac2>
struct samebase {
	typedef typename scalarMultiply<frac2::den, frac1>::result X;
	typedef typename scalarMultiply<frac1::den, frac2>::result Y;
};

template<typename frac1, typename frac2>
struct sum {
	typedef samebase<frac1, frac2> B;
	static const ll num = B::X::num + B::Y::num;
	static const ll den = B::X::den * B::Y::den;
	typedef fraction<num, den> result;
};

template<ll N>
struct E {
	static const ll cur = factorial<N>::result;
	typedef fraction<1LL, cur> term;
	typedef typename E<N - 1LL>::result next_term;
	typedef typename sum<term, next_term>::result result;
};

template<>
struct E<0> {
	typedef fraction<1LL, 1LL> result;
};

int main(int argc, char** argv) {

	//e = S(1/n!) = 1/0! + 1/1! + 1/2! + 1/3! + 1/4! + ...
	typedef E<8>::result X;
	std::printf("%0.20lf\n", (1.0* X::num / X::den));
	std::cout << "e = " << (1.0 * X::num / X::den) << '\n';
	std::cout << "e = " << X::num << "/" << X::den << '\n';

	return 0;
}
