//Example below show what implicit conversion doo
// #include <iostream>
// using namespace std;
//
// class Foo {
// public:
//     Foo(int foo) : m_foo(foo) { }
//     int GetFoo() { return m_foo; }
// private:
//     int m_foo;
// };
//
// //below function do implicit conversion
// void DoBar(Foo foo) {
//     int i = foo.GetFoo();
//     cout << i << endl;
// }
//
// int main(int argc, char** argv) {
//     
//     DoBar(42); //print 42 
//     
//     return 0;
// }
//
//why to avoid implicit conversion
//say we have a MyString(int size) class which creates a string of size given
//and then we have a function print(const MyString&) and in main we call it
//like this print(3); so we expect to print "3" but it prints an empty string
//whose lenght is 3

//Explicit constructor
#include <iostream>

class Foo {
public:
	explicit Foo(int foo) : m_foo(foo) {}
	int GetFoo() { return m_foo; }
private:
	int m_foo;
};

void DoBar(Foo foo) {
	std::cout << foo.GetFoo() << std::endl;
}

int main(void) {

	// DoBar(3); //Error
	DoBar(Foo(3)); //prints 3

	return 0;
}
