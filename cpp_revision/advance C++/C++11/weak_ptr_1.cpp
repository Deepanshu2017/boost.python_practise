#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Girl {
	public:
		string m_name;
		Girl(string name) {
			m_name = name;
			cout << "name is: " << name << endl;
		}
		void makeFriend(shared_ptr<Girl> g) {
			m_pFriend = g;
		}
		void print() {
			if(!m_pFriend.expired())
				cout << m_pFriend.lock()->m_name << endl;
		}
		~Girl() {
			cout << "destructor" << endl;
		}
	private:
		weak_ptr<Girl> m_pFriend;
};

int main(int argc, char** argv) {

	shared_ptr<Girl> g1 = make_shared<Girl>("Pooja");
	shared_ptr<Girl> g2 = make_shared<Girl>("Vaishali");
	(*g1).makeFriend(g2);
	g2->makeFriend(g1);
	g1->print();
	g2->print();
	g1.reset();
	g2->print();
	return 0;
}
