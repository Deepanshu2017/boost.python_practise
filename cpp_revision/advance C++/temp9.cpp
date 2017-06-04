#include <iostream>
using namespace std;

namespace Pooja {
	class Deepanshu {
		public:
			int var = 5;
			void print() {
				cout << "var is: " << var << endl;
			}
	};
}

void foo(Pooja::Deepanshu &d) {
	d.print();
}

int main(void) {
	
	Pooja::Deepanshu pd;
	foo(pd);

	return 0;
}
