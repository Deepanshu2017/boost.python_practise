#include <iostream>
#include <regex>
using namespace std;

int main(int argc, char** argv) {

	string str = "<email>deepanshu2017@gmail.com<email>\
				  <email>deepanshu2017@hotmail.com<email>\
				  <email>deepanshu2013@yahoo.com<email>";
	regex reg("([[:w:]]+)@([[:w:]]+)\\.com");
	
	// sregex_token_iterator pos(str.begin(), str.end(), reg);
	sregex_token_iterator pos(str.begin(), str.end(), reg, 0);
	sregex_token_iterator end;
	for(; pos!= end; ++pos)
		cout << "email: " << pos->str() << endl;

	cout << endl << endl;

	cout << regex_replace(str, reg, "$1 is on $2\n", regex_constants::format_no_copy | regex_constants::format_first_only);
	cout << endl;
	
	return 0;
}
