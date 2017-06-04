//avoid using default parameters for virtual functions
//maintain is-a relationship anyhow for public inheritance
#include <iostream>
using namespace std;

class Dog {
	public:
		void bark(int age) {
			cout << "I am " << age << " years old" << endl;
		}
		virtual void bark(string msg = "just a") {
			cout << "I am " << msg << " dog" << endl;
		}
};

class YellowDog : public Dog {
	public:
		using Dog::bark; //bark was shadowed by virtual function so to
		//maintain is-a relationship we have to force inherited shadowed
		//function
		virtual void bark(string msg = "YellowDog") {
			cout << "I am a " << msg << endl;
		}
};

int main(void) {
	
	YellowDog *py = new YellowDog();
	py->bark();
	Dog *pd = py;
	pd->bark(5);

	return 0;
}
