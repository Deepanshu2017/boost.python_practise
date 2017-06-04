//lvalue is something that has address and modifiable and we can
//store some data in that memory
//int i = 5;
//    ^--------->i is lvalue
//        ^----->5 is rvalue
//because we can get address of i but we cannot get the address of 5
//
//int i = 5;
//int var = i;
//          ^---> i is lvalue but in the above context i is implicity
//          transformed into rvalue
//so lavlue can be implicitly transformed into rvalue but otherway
//around is not possible. To transform rvalue into lavlue we have to
//do it explicitly
//int v[10];
//*(v + 2) = 5;
//  ^^^^^---------> v + 2 is rvalue but *(v + 2) is lvalue
//Every C++ expression uses either rvalue or lvalue
//If the expression has an identifiable memory address, it's lvalue
//other wise it is rvalue
//C defination of lvalue-->"value suitable for left hand side ofassignment"
//^above defination is no longer true in C++


#include <iostream>
using namespace std;
int myglobal = 0;

int &foo() {
	return myglobal;
}

int main(void) {

	foo() = 50;
	cout << myglobal << endl;

	return 0;
}
