//The below code is for demo purpose only
//it may not even compile
//
/*
 * static cast:
 * can convert one object to anoter type object
 * Up/down both casting are allowd
 * works with related types only
 *
 */

/*
 * Dynamic cast:
 * can convert pointer/refrence to another realted
 * down casting only
 * works on runtime
 * if successful assign poiter other wise assign null
 *
 */

/*
 * Const cast:
 * works only with same data type
 * cast away the consteness
 *
 */

/*
 * reinterpret cast:
 * works with any pointer/refrence
 * reinterprest the bytes to object specified by the location
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Girl {
	public:
		Girl(string name) {
			m_name = name;
		}
		operator string() const {
			return m_name;	
		}
		void print() {
			cout << m_name << endl;
		}
	private:
		string m_name;
};

class MyGirl: public Girl {
};

int main(void) {

	int i = 9;
	float f = static_cast<float>(i); //covert object from one type to another
	Girl g = static_cast<Girl>(string ("Pooja"));   //type converter needs to 
													//be defined
	Girl *pg = static_cast<Girl*>(new MyGirl());    //convert pointer/refrence 
							//from one type to another realted type (down/up)

	Girl *p = new MyGirl();
	MyGirl mg = dynamic_cast<MyGirl*>(p); 
	//Dynamic cast convert pointer/refrence from one type to realted type
	//down cast only
	//Performs run-time check if succedd mg = p else mg = 0
	//it requires two type to be polymorphic means they must have atleast
	//one virtual fucnction
	

	const char* str = "Pooja";
	char* modifiable = const_cast<char *>(str);
	//can work with pointer/refrences only
	//only works on same type
	//cast away the constentness
	

	long lp = 0x7c008700; //some random address
	Girl *dd = reinterpret_cast<Girl *>(lp);
	//re-interperts the bits of the object pointed to
	//it can cast any type of pointer to any other type of pointer


	return 0;
}
