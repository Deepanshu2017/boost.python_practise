#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Person {
	private:
		unique_ptr<string> pName_;
	public:
		Person(string name) : pName_(new string(name)) {}
		~Person() {}
		Person(Person&&) = default;
		void printName() { cout << *pName_ << endl; }
};

int main(void) {

	vector<Person> persons;
	Person p = Person("George");
	persons.push_back(move(p));
	persons.front().printName();

	return 0;
}
