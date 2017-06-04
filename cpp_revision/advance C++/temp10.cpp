#include <string>
#include <iostream>
using namespace std;

class Pooja {
	private:
    string& m_name;
	public:
    Pooja(string& name) : m_name(name) { }
    void mutator() { cout << "name is: " << m_name << endl; m_name = m_name + string(" Tiwari"); }
    ~Pooja() { }
};

int main(int argc, char** argv) {
    
    string name = "Pooja";
    Pooja pooja(name);
    pooja.mutator();
    cout << name << endl;

    return 0;
}
