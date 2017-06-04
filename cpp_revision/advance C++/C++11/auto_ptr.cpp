//depricated with unique pointer
#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Girl {
	public:
		string m_name;
		void speak() { cout << "Girl " << m_name << " rules!" << endl; }
		Girl() { cout << "Nameless girl created\n"; m_name = "Nameless"; }
		Girl(string name) { cout << "Girl is: " << name << endl; m_name =name;}
		~Girl() { cout << "Girl is destroyed: " << m_name << endl; }
};

void test() {
	auto_ptr<Girl> g(new Girl("Pooja"));
	g->speak();
}

int main(void) {
	test();
	return 0;
}
