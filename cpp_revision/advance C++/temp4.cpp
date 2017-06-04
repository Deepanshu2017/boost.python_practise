#include <bits/stdc++.h>
using namespace std;

class Collar {
	public:
		int var_ = 4;
};

class Dog { 
	private:
		Collar *pCollar;
	public:
		Dog() {
			pCollar = new Collar();
		}
		void set(int var) {
			this->pCollar->var_ = var;
		}
		void display() {
			cout << this->pCollar->var_ << endl;
		}
		Dog& operator=(const Dog& rhs) {
			if(this == &rhs)
				return *this;
			delete pCollar;
			pCollar = new Collar(*(rhs.pCollar));
			return *this;
		}
};

int main(void) {

	Dog d1;
	d1.set(10);
	Dog d2;
	d2.set(20);
	d1.display();
	d2.display();
	d2 = d1;
	d1.display();
	d2.display();
	d2.set(30);
	d1.display();
	d2.display();

	return 0;
}
