#include <iostream>
using namespace std;

namespace A {
	struct X { };
	void foo(X x1) {
		cout << "I am in A::foo" << endl;
	}
}

class B {
	public:
		void foo(A::X) {
			cout << "I am in B::foo" << endl;
		}
};

class C : public B {
	public:
		void j() {
			A::X x;
			foo(x);
		}
};

int main(void) {
	
	A::X x1;
	foo(x1); //koeing lookup Compiler will not only search in global scope
			 //and current scope but also search function declaration where
			 //paramerter type is defined koeing lookup applies only for
			 //namespace

	C c;
	c.j(); //class members are tightly bound with each other and copiler
		   //will search for all member functions declaration into class
		   //first and only search outside and use koeing lookup if 
		   //defination is not found!

	return 0;
}
