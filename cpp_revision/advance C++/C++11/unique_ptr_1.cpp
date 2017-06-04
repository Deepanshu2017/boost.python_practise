#include <iostream>
#include <memory>
#include <string>
#include <typeinfo>
using namespace std;

class Girl {
	public:
		string m_name;
		Girl() { cout << "constructor of Girl" << endl; m_name = "Nameless"; }
		Girl(string name) { m_name = name; cout << "Hell" << endl; }
		~Girl() { cout << "destructor" << endl; }
		void speak() { cout << m_name << endl; }
};

template<typename T>
void foo(T&& p) {
	// cout << typeid(p).name() << " " << typeid(p).hash_code() << endl;
	p->speak();
}

int main(int argc, char* argv[]) {
	
	unique_ptr<Girl> g(new Girl());
	// cout << typeid(g).name() << " " << typeid(g).hash_code() << endl;
	foo(g);
	// cout << typeid(g).name() << " " << typeid(g).hash_code() << endl;
	if(g)
		cout << "G is not empty" << endl;
	else
		cout << "G is empty" << endl;

	return 0;
}
