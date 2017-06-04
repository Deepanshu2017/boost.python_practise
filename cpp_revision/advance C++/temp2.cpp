#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class Static_Ploymorphism {
	public:
		void process() {
			static_cast<T*>(this)->bark();
		}
};

class Dog : public Static_Ploymorphism<Dog> {
	public:
		Dog() {
			cout << "I am n contructor of class Dog" << endl;
		}
		virtual void bark() {
			cout << "I am bark of class Dog" << endl;
		}
}; 

class YellowDog : public Static_Ploymorphism<YellowDog> {
	public:
		YellowDog() {
			cout << "I am in contructor of YellowDog" << endl;
		}
		virtual void bark() {
			cout << "I am in bark of YellowDog" << endl;
		}
};

class Test : virtual public Dog, virtual public YellowDog {
	public:
		Test() {
			cout << "I am constructor of class test" << endl;
		}
		void bark() {
			cout << "I am in bark function of class test" << endl;
		}
};
	
int main(void) {

	Dog *pDog = new Dog();
	YellowDog *pyellowDog = new YellowDog();
	pDog->process();
	pyellowDog->process();
	Test *pTest = new Test();
	cout << endl << endl;
	pTest->process();

	return 0;
}
