#include <bits/stdc++.h>
using namespace std;

class Rational {
	public:
		int num_ = 10, den_ = 5;
		Rational(int num = 10, int den = 5) {
			cout << "I am in constructor" << endl;
			num_ = num;
			den_ = den;
		}
		
		virtual ~Rational() {
			cout << "Destructor of Rational" << endl;
		}
};

Rational operator* (const Rational &lhs, const Rational &rhs) {
	return (Rational(lhs.num_ + rhs.num_, lhs.den_ + lhs.den_));
}

int main(void) {

	Rational r1 = 3;
	Rational r2 = r1 * 2;

	return 0;
}
