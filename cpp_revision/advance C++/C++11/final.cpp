//make virtual function final to prevent overriding function in class
//hirerchy
//We cannnot make any non-virtual function final
//make class final to prevent making its derive class

#include <iostream>
using namespace std;

class Girl {
public:
	virtual void foo() { cout << "I am in foo of Girl" << endl; }
};

class Pooja : public Girl {
public:
	virtual void foo() final override { cout << "I am in foo of Pooja\n"; }
};

class Shrishti : public Pooja {
public:
	//virtual void foo() override { cout << "temp\n"; } // error cannot
	//override final member function
};

int main(void) {

	Shrishti s;
	s.foo();
	return 0;
}
