#include <bits/stdc++.h>
using namespace std;

template<typename T>
void foo(T&& var) {
	cout << var << " ";
	cout << typeid(var).name() << endl;
}

template<typename T>
void relay(T&& arg) {
	foo(forward<T>(arg));
}

int main(void) {
	
	relay(5);
	relay(5.5);
	
	return 0;
}