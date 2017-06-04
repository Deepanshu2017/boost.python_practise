#include <iostream>
using namespace std;
//bark and Run are common because all Dog's bark and Run

class Composition {
	public:
		void bark(string name) {
			cout << "I am barking and I am " << name << endl;
		}
		void run(int speed) {
			cout << "I am running and my speed is " << speed << endl;
		}
};

class Dog {
	public:
		void specialOfDog() {
			cout << "I am simple Dog" << endl;
		}
		virtual void bark(string name) {
			ActivityManager->bark(name);
		}
		virtual void run(int speed) {
			ActivityManager->run(speed);
		}
	private:
		Composition *ActivityManager;
};

class YellowDog : public Dog {
	public:
		void specialOfYellowDog() {
			cout << "I am YellowDog" << endl;
		}
		void bark(string name) {
			ActivityManager->bark(name);
		}
		void run(int speed) {
			ActivityManager->run(speed);
		}
	private:
		Composition *ActivityManager;
};

class ShepheredDog : public Dog {
	public:
		void specialOfShepherdDog() {
			cout << "I am Shepherd Dog" << endl;
		}
		void bark(string name) {
			ActivityManager->bark(name);
		}
		void run(int speed) {
			ActivityManager->run(speed);
		}
	private:
		Composition *ActivityManager;
};

int main(void) {

	Dog d;
	YellowDog y;
	ShepheredDog s;

	d.specialOfDog();
	d.bark(string("Dog"));
	d.run(50);

	y.specialOfYellowDog();
	y.bark(string("Yellow Dog"));
	y.run(65);

	s.specialOfShepherdDog();
	s.bark(string("Shepherd Dog"));
	s.run(67);

	return 0;
}
