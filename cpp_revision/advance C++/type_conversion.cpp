//Standard type conversion: convert objects between built-in type
//User Defined Type Conversion: convert between two classess and/or 
//class and bulit-in type

#include <iostream>
using namespace std;

class Girl {
	public:
		//explicit means: 
		//Contructor + explicit type converter
		explicit Girl(string name) {	
			// If you want to define a contstructor
			//and no implicit type conversion then always put
			//explicit before the constructor to avoid INADVERTENT
			//type conversion 
			m_name = name;
		}
	private:
		string m_name;
};

class Rational {
	public:
		Rational(int num = 0, int den = 1) {
			m_num = num;
			m_den = den;
		}
		void print() {
			cout << m_num << " " << m_den << endl;
		}
		operator int() const {
			return m_num / m_den;
		}
	private:
		int m_num;
		int m_den;
};

int main(void) {
	
	string GirlName = "Pooja";
	Rational r = Rational(24, 2);
	r.print();
	Rational r2 = r * 3;
	r2.print();
	return 0;
}
