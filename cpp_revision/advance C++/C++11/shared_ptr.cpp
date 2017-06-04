#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Girl {
private:
	string name_;
public:
	Girl(string name) {
		cout << "Girl is created: " << name << endl;
		name_ = name;
	}
	Girl() {
		cout << "Nameless girl is created" << endl;
		name_ = "Nameless";
	}
	~Girl() {
		cout << "Girl is destroyed " << name_ << endl;
	}
	void speak() {
		cout << "Girl " << name_ << " rules!" << endl;
	}
};

void foo() {
	shared_ptr<Girl> p(new Girl("Pooja"));
	{
		shared_ptr<Girl> p2 = p;
		p2->speak();
		cout << p.use_count() << endl;
	}
	p->speak();
}

void foo2() {
	shared_ptr<Girl> p1 = make_shared<Girl>("Pooja");
	shared_ptr<Girl> p2 = make_shared<Girl>();
	p2 = p1;		//"Nameless" girl is deleted
	p2 = nullptr;	//"Nameless" girl is deleted
	p2.reset();		//"Nameless" girl is deleted

	shared_ptr<Girl> p3 = shared_ptr<Girl>(new Girl(), 
				[](Girl *ptr) {
					cout << "I am in lambda function" << endl;
					delete ptr;
				}
			);

	// shared_ptr<Girl> ptr_array(new Girl[3]); //memory leak
	shared_ptr<Girl> ptr_array(new Girl[3], 
				[](Girl *ptr) {
					cout << "Lambda function" << endl;
					delete []ptr;
				}
			);

}

int main(void) {

	shared_ptr<Girl> pt = make_shared<Girl>("Pooja");
	Girl *ptr = pt.get();	
	ptr->speak();
	pt.reset();
	// delete ptr; // double free

	return 0;
}
