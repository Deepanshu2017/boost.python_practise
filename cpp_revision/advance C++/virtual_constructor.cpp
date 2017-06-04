#include <iostream>
using namespace std;

class Dog {
	public:
		virtual Dog* clone() {
			return (new Dog(*this));
		}
};

class YellowDog : public Dog {
	public:
		virtual YellowDog* clone() {
			cout << "I am in foo of YellowDog class" << endl;
			return (new YellowDog(*this));
		}
};

void foo(Dog *pd) {
	Dog *c = pd->clone();
}

int main(void) {

	foo(new YellowDog());

	return 0;
}
