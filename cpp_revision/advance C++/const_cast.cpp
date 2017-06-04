#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
    
    string name = "deepanshu";
    const string* pString_1 = &name;
    string* pString_2 = const_cast<string*>(pString_1);
    cout << *pString_2 << endl;
    *pString_2 = "Deepanshu Thakur";
    cout << name << endl;
    cout << *pString_1 << endl;
    cout << *pString_2 << endl;
//    pString_1 = "Deepanshu"; //Error
 
	return 0;

}
