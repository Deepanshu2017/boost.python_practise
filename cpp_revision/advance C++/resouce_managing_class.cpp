#include <bits/stdc++.h>
using namespace std;

class Person {
	public:
		Person(string name) {
			pName_ = new string(name);
		}
		void print() {
			cout << *pName_;
		}
		~Person() {
			delete pName_;
		}

		string* getName() const {
			return pName_;
		}
		
	private:
		Person(const Person &rhs) {
			pName_ = new string(*(rhs.getName()));
		}

		Person& operator=(const Person &rhs) {
			pName_ = new string(*(rhs.getName()));
		}

		string *pName_;
};

int main(void) {
	vector<Person*> persons;
	persons.push_back(new Person("Pooja"));
	persons.back()->print();

	cout << "Good Bye" << endl;

	return 0;
}
