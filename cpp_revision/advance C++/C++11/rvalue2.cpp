#include <bits/stdc++.h>
using namespace std;
#define POOJA cerr << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP" << endl

class Pooja {
		private:
			int size;
			int* arr_;
		public:
			int getSize() const {
				return size;
			}
			int getArray(const int idx) const {
				return arr_[idx];
			}
			int* getArrayIndex() const {
				return arr_;
			}
			void setArrayIndex() {
				arr_ = nullptr;
			}
			Pooja(const int size, const int val = 10) {
				cerr << "constructor count" << endl;
				this->size = size;
				arr_ = new int[size];
				for(int i = size; i--; ) {
					arr_[i] = val;
				}
			}	
			void deepCopy(const Pooja &rhs) {
				size = rhs.getSize();
				arr_ = new int[size];
				for(int i = size; i--;)
					arr_[i] = rhs.getArray(i);
			}
			void shallowCopy(Pooja&& rhs) {
				this->size = rhs.getSize();
				this->arr_ = rhs.getArrayIndex();
				rhs.setArrayIndex();
			}
			Pooja(const Pooja &rhs) {
				cerr << "deep constructor" << endl;
				this->deepCopy(rhs);
			}
			Pooja(Pooja&& rhs) {
				cerr << "Move constructor" << endl;
				this->shallowCopy(forward<Pooja>(rhs));  //forward turn rhs into type of T&&
				// this->shallowCopy(move(rhs));		 //move turn rhs into an rvalue type
			}
			void operator= (const Pooja &rhs) {
				cerr << "deep operator =" << endl;
				this->deepCopy(rhs);
			}
			void operator= (Pooja&& rhs) {
				cerr << "Move operator = " << endl;
				this->shallowCopy(forward<Pooja>(rhs));
				// this->shallowCopy(move(rhs));
			}
			void display() {
				for(int i = size; i--;)
					cout << arr_[i] << " ";
				cout << endl;
			}
			~Pooja() {
				delete arr_;
			}
};

void foo(Pooja p) {
	p.display();
}

Pooja createPooja() {
	return Pooja(10, 40);
} 

int main(void) {
	
	Pooja p1(10, 10);
	Pooja p2(10, 20);
	p2 = Pooja(10, 30);
	POOJA;
	p2.display();
	p2 = p1;
	p2.display();
	foo(move(p2));
	
	return 0;
}
