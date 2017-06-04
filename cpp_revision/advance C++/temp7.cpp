#include <iostream>
using namespace std;

class Base {
	public:
		void f_pub() {
			cout << "f_pub is called" << endl;
		}
	private:
		void f_priv() {
			cout << "f_priv is called" << endl;
		}
	protected:
		void f_prot() {
			cout << "f_prot is called" << endl;
		}
};

class D_public : public Base {
	public:
		using Base::f_prot;
		void f() {
			f_pub();
			f_prot();
		}
};

class D_Protected : protected Base {
	public:
		using Base::f_pub;
		using Base::f_prot;
		void f() {
			f_pub();
			f_prot();
		}
};

class D_Private : private Base {
	public:
		using Base::f_pub;
		using Base::f_prot;
		void f() {
			f_pub();
			f_prot();
		}
};

int main(void) {

	D_public d1;
	d1.f_pub();
	d1.f_prot();
	cout << "Public is done" << endl << endl;

	D_Protected d2;
	d2.f_pub();
	d2.f_prot();
	cout << "Protected is done" << endl << endl;

	D_Private d3;
	d3.f_pub();
	d3.f_prot();

	return 0;
}
