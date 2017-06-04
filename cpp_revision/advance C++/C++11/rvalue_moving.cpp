#include <bits/stdc++.h>
using namespace std;

class PT {
	public:
		int size;
		double* arr_;
		PT() {
			size = 10;
			arr_ = new double[size];
			for(int i = 0; i < size; ++i)
				arr_[i] = 10;
		}
		PT(const PT& rhs) {
			cout << "Copy constructor of reference: " << endl;
			size = rhs.size;
			arr_ = new double[size];
			for(int i = 0; i < size; ++i)
				arr_[i] = rhs.arr_[i];
		}
		PT(PT&& rhs) {
			cout << "Copy constructor of rvalue reference: " << endl;
			size = rhs.size;
			arr_ = rhs.arr_;
			rhs.arr_ = nullptr;
		}
		~PT() {
			delete arr_;
		}
};

void foo(PT v) {
	cout << "I am in foo" << endl;	
}

PT create() {
	PT y;
	return y;
}

int main(void) {

	foo(create());	

	return 0;
}
