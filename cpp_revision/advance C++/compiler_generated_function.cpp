#include <iostream>
using namespace std;

//Compiler will try to generate these 4 functions if required
//Copy constructor //Member by member copy
//Copy assignment operator 
//Destructor
//Default constructor (if no constructor is provided)

class Girl {
	public:
		string name;
		Girl(string name = "Pooja") {
			this->name = name;
			cout << "girl name is: " << name  << endl;
		}
		~Girl() {
			cout << "Girl name is: " << name << endl;
		}
};

class Dog {
	public:
		string &name;
		//No default constructor, copy assignment operator, copy constructor
		//will be generated because name is a refrence
};

int main(void) {

	Girl g1;
	Girl g2("Anshu");
	g2 = g1; //compiler generated copy assignment operator
	//Only those functions will be generated which are used in the program
	
	//Dog d; //Error

	return 0;
}
