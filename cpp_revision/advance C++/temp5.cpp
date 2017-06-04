#include <bits/stdc++.h>
using namespace std;

class Dog {
	private:
		~Dog() {
			cout << "I am dying bye!" << endl;
		}
	public:
		Dog() {
			cout << "I am in constructor of Dog" << endl;
		}
		void bark() {
			cout << "I am in bark" << endl;
		}
		friend void destroyMe(Dog *rhs); 
};

void destroyMe(Dog *rhs) {
	delete rhs;
}

int main(void) {

	shared_ptr<Dog> pd = shared_ptr<Dog>(new Dog, destroyMe);
	pd->bark();

	return 0;
}
