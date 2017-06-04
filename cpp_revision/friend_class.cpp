#include <iostream>
using namespace std;

//This program demostrates how we can access private member
//of a class in main function with using member function of class

class B;
class A {
	private:
		int foo = 0;
	public:
		int& mul(B&);
};

class B {
	private:
		int foo2 = 5;
	public:
		friend class A;
		void print() {
			cout << foo2 << endl;
		}
};

int& A::mul(B& b) {
	cout << "Accessing private members of class B" << endl;
	cout << b.foo2 << endl;
	return b.foo2;
}

int main(void) {

	B b;
	A a;
	int &var = a.mul(b);
	b.print();
	var = 8;
	b.print();

	return 0;
}
