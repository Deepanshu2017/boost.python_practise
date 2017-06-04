#include <iostream>
using namespace std;

class B;
class A {
private:
    ~A() { cout << "destructor of class A" << endl; }
public:
    friend class B;
};

class B {
public:
    void destroy(A* obj) {
	    delete obj;
	}
    ~B() { cout << "destructor of class B" << endl; }
};

int main(int argc, char** argv) {
    
    A* obj = new A();
    B b;
    b.destroy(obj);
    
    return 0;
}
