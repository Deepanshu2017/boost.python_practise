//shared pointers and virtual destructor
#include <bits/stdc++.h>
using namespace std;

class Dog {
	public:
		~Dog() {
			cout << "I am in destructor of Dog" << endl;
		}
};

class YelloDog : public Dog {
	public:
		~YelloDog() {
			cout << "I am in destructor of YelloDog" << endl;
		}
};

class DogFactory {
	public:
		static shared_ptr<Dog> createYellowDog() {
			return shared_ptr<YelloDog>(new YelloDog());
		}
};

class Girl {
	public:
		virtual ~Girl() { //If a class is going to be used in polymorphic way
			//then it we should use virual destructor of that class so that
			//we can avoid memory leak
			cout << "I am in destructor of Girl" << endl;
		}
};

class MyGirl : public Girl {
	public:
		~MyGirl() {
			cout << "I am in destructor of MyGirl" << endl;
		}
};

class GirlFactory {
	public:
		static Girl * createMyGirl() {
			return new MyGirl();
		}
};

int main(void) {

	shared_ptr<Dog> pd = DogFactory::createYellowDog(); 
	Girl *g = GirlFactory::createMyGirl();
	delete g;

	return 0;
}
