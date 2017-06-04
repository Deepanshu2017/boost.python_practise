#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Girl {
public:
	Girl(string name) : name_(new string(name)) {}
	Girl(Girl&& rhs) : name_(rhs.name_.release()) {}
	~Girl() { cout << "deleted: " << endl; }
	void print() { cout << *name_ << endl; }
private:
	unique_ptr<string> name_;	
};

int main(void) {

	vector<Girl> vec;
	vec.push_back(move(Girl("Pooja")));
	vec.back().print();

	return 0;
}
