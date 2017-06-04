#include <bits/stdc++.h>
using namespace std;

class Person {
	public:
		Person(string name) : pName_(new string(name)) { }
		void print() { cout << *pName_ << endl; }
		~Person() { delete pName_; }
	private:
		string *pName_;
};

int main(void) {
	
	vector<Person> persons;
	// persons.push_back(Person("Pooja"));
	persons.emplace_back("Pooja"); // constructs the object at the end
								   // of the container
	persons.back().print();

	cout << "Good Bye" << endl;

	return 0;
}
