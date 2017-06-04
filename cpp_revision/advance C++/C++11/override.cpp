#include <iostream>
using namespace std;

class Pooja final {
	public:
		virtual void foo(int var) {
			cout << "I am in foo of Pooja" << endl;
		}
		virtual void bar() final {
			cout << "I am in bar of Pooja" << endl;
		}
		virtual ~Pooja() {
			cout << "Bye Bye Pooja" << endl;
		}
};

// class Deepanshu : public Pooja {
// 	public:
// 		virtual void foo(int var) override {
// 			cout << "I am in foo of Deepanshu" << endl;
// 		}
// 		// virtual void bar() override {
// 		// 	cout << "I am in bar of Deepanshu" << endl;
// 		// }
// 		virtual ~Deepanshu() {
// 			cout << "Bye Bye Deepanshu" << endl;
// 		}
// };

int main(void) {

	// Pooja *p = new Deepanshu();
	Pooja *p = new Pooja();
	p->foo(5);
	p->bar();
	delete p;
	p = new Pooja();
	p->foo(5);
	p->bar();
	delete p;

	static_assert(sizeof(int) == 4, "Integer size is short");

	return 0;
}
