#include <iostream>
#include <memory>
using namespace std;

class Girl {
	public:
		Girl() { cout << "constructor of Girl" << endl; }
		virtual void foo(string name) { cout << name << " Girl\n"; }
		virtual ~Girl() { cout << "destructor of Girl\n"; }
		virtual void set(int var) { this->var = var; }
		virtual int get() { return this->var; }
	private:
		int var = 10;
};

class Pooja : public Girl {
	public:
		Pooja() { cout << "constructor of Pooja" << endl; }
		virtual void foo(string name) override {
			cout << name << " Pooja" << endl;
		}
		virtual void set(int var) override { 
			cout << "Pooja" << endl; 
			this->var = var; 
		}
		virtual int get() override { 
			cout << "Pooja" << endl; 
			return this->var; 
		}
		virtual ~Pooja() { cout << "destructor of Pooja\n"; }
	private:
		int var = 0;
};

int main(int argc, char** argv) {

	// shared_ptr<Girl>(g) = make_shared<Pooja>();
	// shared_ptr<Girl>(g2) = g;
	// cout << endl;
	// g->set(5);
	// cout << g->get() << " " << g2->get() << endl;
	// cout << endl;
	// g = dynamic_pointer_cast<Pooja>(g);
	// g->set(10);
	// cout << g->get() << " " << g2->get() << endl;

	auto lambda = [](Girl* pG) { delete[] pG; };
	shared_ptr<Girl> girlArray(new Girl[5], lambda);

	return 0;
}
