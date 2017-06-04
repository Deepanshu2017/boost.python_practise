#include <iostream>
using namespace std;

class wrapper {
	public:
		const int* const fun(const int* const &p) const {
			return p;
		}
};

int main(void) {

	int var = 6;
	const_cast<int&>(var) = 8;
	cout << var << endl;

	int j = 6;
	static_cast<const int&>(j);
	cout << j << endl;

	wrapper wrap;
	const int vari = 5;

	cout << *(wrap.fun(&vari)) << endl;

	return 0;
}
