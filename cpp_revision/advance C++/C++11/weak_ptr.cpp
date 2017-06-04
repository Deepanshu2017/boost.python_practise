#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Girl {
private:
	// shared_ptr<Girl> pFriend_; //cyclic refrence so no deletion will be
	// performed on the object pointed by shared pointers :(
	weak_ptr<Girl> pFriend_; //waek pointer is like raw pointer but
   //it is safe because object cannot be deleted with weak pointer	
public:
	string name_;
	void speak() {
		cout << "Girl " << name_ << "  rules!" << endl;
	}
	Girl(string name) {
		cout << "Girl is created " << name_ << endl;
		name_ = name;
	}
	~Girl() {
		cout << "Girl is destroyed " << name_ << endl;
	}
	void makeFriend(shared_ptr<Girl> g) {
		pFriend_ = g;
	}
	void showFriend() {
		if(!pFriend_.expired())
			cout << "My friend is: " << pFriend_.lock()->name_ << endl;
		cout << "Number of count is: " << pFriend_.use_count() << endl;
	 }
};

int main(void) {

	shared_ptr<Girl> pG = make_shared<Girl>("Pooja");
	shared_ptr<Girl> pG2 = make_shared<Girl>("Nameless");
	pG->makeFriend(pG2);
	pG2->makeFriend(pG);
	pG->showFriend();
	pG2->showFriend();

	return 0;
}
