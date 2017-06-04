#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Dog {
	private:
	public:
		string name;
		void bark() {
			cout << "Dog " << name << " rules!" << endl;
		}
		Dog() {
			cout << "Nameless dog created." << endl;
			name = "Nameless";
		}
		Dog(string name) {
			this->name = name;
			cout << "dog is created: " << name << endl;
		}
		~Dog() {
			cout << "dog is destroyed: " << name << endl;
		}
};

void test() {
	unique_ptr<Dog> pD(new Dog("Gunner"));
	pD->bark();
}

int main(void) {

	test();

	return 0;
}
