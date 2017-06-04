#include <iostream>
using namespace std;

int main(int argc, char** argv) {

	int i = 5;
	cout << &++i << endl;
	// cout << &i++ << endl; //Error rvalue
	cout << &cin << endl;
	int& ii = static_cast<int&>(i);
	cout << &ii << endl;
	i = ii = 8;
	cout << i << " " << ii << endl;
	int a = 5, b = 6;
	cout << &a << endl;
	cout << &b << endl;
	cout << &(a > b ? a : b) << endl;

	return 0;
}
