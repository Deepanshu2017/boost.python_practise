#include <memory>
#include <iostream>
using namespace std;

class Dog {
public:
    ~Dog() { cout << "Destructor of dog" << endl; }
};

class YellowDog : public Dog {
public:
    ~YellowDog() { cout << "Destructor of YellowDog" << endl; }
};

class DogFactory {
public:
    static shared_ptr<Dog> createYellowDog() {
	        return shared_ptr<YellowDog>(new YellowDog());
	    }
};

int main(int argc, char** argv) {
    
    shared_ptr<Dog> pd = DogFactory::createYellowDog();
    
    return 0;
}
