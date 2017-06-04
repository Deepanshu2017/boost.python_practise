#include <iostream>
#include <regex>
using namespace std;

int main(void) {

	string str = "deepanshu2017@gmail.com; \
				  deepanshu2017@hotmail.com; \
				  deepanshu2013@yahoo.com;";
	regex reg("([[:w:]]+)@([[:w:]]+)\\.com");
	sregex_iterator pos(str.cbegin(), str.cend(), reg);
	sregex_iterator end;
	for(; pos != end; ++pos) {
		cout << pos->str(0) << endl;
		cout << pos->str(1) << endl;
		cout << pos->str(2) << endl;
		cout << endl;
	} 
	cout << "================================" << endl;
	return 0;
}
