//constness is a compiler time constraint that a object cannot be modified
#include <iostream>
using namespace std;

class Dog {
	int age;
	string name;
	public:
	Dog() {
		age = 3;
		name = "Dummy";
	}

	void print_name() {
		cout << name << " non-const" << endl;
	}

	void print_name() const { //const can be used to overload function
		cout << name << " const" << endl;
	}

	void setname(string &name) {
		this->name = name;
		cout << "I am in non const version" << endl;
	}

	void setname(const string &name) {
		this->name = name;
		cout << "I am in const version" << endl;
	}

};

int main(void) {

	//If const is on the left of the *, data is const
	//If const is on the right of the *, pointer is const

	int i = 0;
	int const *p = &i;
	p++;
	//*p = 6; //Error Data is content
	
	int j = 6;
	int * const p1 = &j;
	*p1 = 7;
	//p1++; //Error Pointer is constant

	Dog d1;
	const Dog d2;
	d1.print_name(); //Non const member will call non const version of function
	d2.print_name(); //const member will call const version of overloaded function
	string s1 = "dummy";
	const string s2 = "dummy";
	Dog d3;
	Dog d4;
	d3.setname(s1);
	d4.setname(s2);
	return 0;
}
