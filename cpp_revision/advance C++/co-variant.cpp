#include <iostream>
using namespace std;

class Girl {
	public:
		virtual Girl* clone() { //co-variant return type virtual overriden 
			return (new Girl(*this)); //with differnet return type function
		}
		virtual void foo() {
			cout << "I am in foo of Girl" << endl;
		}
};

class MyGirl : public Girl {
	public:
		virtual MyGirl* clone() { //same overriden virtual function with 
			return (new MyGirl(*this)); //different return value
		}
		virtual void foo() {
			cout << "I am in foo of MyGirl" << endl;
		}
};

void foo(Girl *g) {
	Girl *pg = g->clone();
	pg->foo();
	return;	
}

int main(void) {

	MyGirl m;
	foo(&m);

	return 0;
}
#include <iostream>
using namespace std;

class Girl {
	public:
		virtual Girl* clone() { //co-variant return type virtual overriden 
			return (new Girl(*this)); //with differnet return type function
		}
		virtual void foo() {
			cout << "I am in foo of Girl" << endl;
		}
};

class MyGirl : public Girl {
	public:
		virtual MyGirl* clone() { //same overriden virtual function with 
			return (new MyGirl(*this)); //different return value
		}
		virtual void foo() {
			cout << "I am in foo of MyGirl" << endl;
		}
};

void foo(Girl *g) {
	Girl *pg = g->clone();
	pg->foo();
	return;	
}

int main(void) {

	MyGirl m;
	foo(&m);

	return 0;
}
