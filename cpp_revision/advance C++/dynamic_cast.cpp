#include <bits/stdc++.h>
using namespace std;

class Dog {
	public:
		Dog() {
			cout << "I am in constructor of Dog" << endl;
		}
		virtual void bark() {
			cout << "I am a dog" << endl;
			var = 5;
		}
		int var = 0;
};

class YellowDog : public Dog {
	public:
		YellowDog() {
			cout << "I am in contructor of YellowDog" << endl;
		}
		virtual void bark() {
			cout << "I am a YellowDog" << endl;
			var = 5;
		}
		int var;
};

int main(void) {

	Dog *d = new YellowDog();
	YellowDog *py = dynamic_cast<YellowDog*>(d);
	py->bark();

	return 0;
}
