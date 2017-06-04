#include <iostream>
#include <typeinfo>
using std::cout;
using std::endl;

class Dog {
	public:
		Dog() {
			cout << "I am in Dog's constructor" << endl;
		}
		virtual void foo() {
			cout << "I am in foo of Dog" << endl;
		}
		virtual ~Dog() {
			cout << "I AM IN DESTRUCTOR OF DOG" << endl;
		}
};

class YellowDog : public Dog {
	public:
		YellowDog() {
			cout << "I am in YellowDog's default contructor" << endl;
		}
		virtual void foo() {
			cout << "I am in foo of YellowDog" << endl;
		}
		virtual ~YellowDog() {
			cout << "I AM IN DESTRUCTOR OF YELLOWDOG" << endl;
		}
};

int main(void) {

	Dog *py = new YellowDog(); //This is a implicit static cast
	py->foo();
	YellowDog *pd = dynamic_cast<YellowDog *>(py);
	if(pd) {
		pd->foo();
	}
	py->foo();
	pd->foo();
	delete pd;

	// Dog *py = new YellowDog();
	// py->foo();
	// Dog *pd = dynamic_cast<Dog *>(py); //pd is actually a yellowdog still
	// if(pd) {						   //because py is holding yellowdog
	// 	pd->foo();
	// }
	// py->foo();
	// delete pd;
	// delete pd; //why error on deleting pd?
	// Okay so pd is actually pointing to the same memory location
	// which is pointed by py so deleting py also deletes pd that's
	// why though I am not sure!
	// hamna naya pointer banaya pd
	// pd ka memory mili lakin object thora na mila ha
	// or pd memory location laga
	// jab hamnda py ko pd ma cast kiya means pd or py dono same location
	// par point kar raha ha so yes I think I am right
	return 0;
}
