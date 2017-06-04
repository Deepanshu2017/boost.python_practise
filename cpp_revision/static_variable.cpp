#include <iostream>
using namespace std;

class math {
	public:
		static int sq(int var) {
			return var * var;
		}

		// static int mul(int var1, int var2) const { // error static member
		// function cannot be const as it is possible that these member
		// functions are called with class name only in that case we cannot
		// access this pointer and when we make const class member only this
		// pointer is marked as const
		static int mul(int var1, int var2) {
			return var1 * var2;
		}
};

int main(void) {

	math m1;

	cout << m1.sq(3) << " " << m1.mul(2, 3) << endl;
	cout << math::sq(3) << " " << math::mul(2, 3) << endl;

	return 0;
}
