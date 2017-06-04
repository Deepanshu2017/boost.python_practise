#include <iostream>
using namespace std;

class B;
class A {
	private:
		int m_var_a = 5;
	public:
		A(int var) : m_var_a(var) {}
		friend int mul(A, B);
};

class B {
	private:
		int m_var_b = 4;
	public:
		B(int var) : m_var_b(var) {}
		friend int mul(A, B);
};

int mul(A a, B b) {
	return a.m_var_a * b.m_var_b;
}

int main(void) {

	cout << mul(A(4), B(3)) << endl;

	return 0;
}
