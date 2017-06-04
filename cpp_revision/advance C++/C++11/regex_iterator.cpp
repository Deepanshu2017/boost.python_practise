#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main(void) {

	string str;
	int i = 5;
	/*
	while(i--) {
		cin >> str;
		regex e("([[:w:]]+)@([[:w:]]+)\.com");
		sregex_iterator pos(str.cbegin(), str.cend(), e);
		sregex_iterator end;
		for(; pos != end; ++pos) {
			cout << "Matched: " << pos->str(0) << endl;
			cout << "username: " << pos->str(1) << endl;
			cout << "domain name: " << pos->str(2) << endl;
		}
	}
	*/

	while(i--) {
		cin >> str;
		regex e("([[:w:]]+)@([[:w:]]+).com");
		sregex_token_iterator pos(str.cbegin(), str.cend(), e);
		sregex_token_iterator end;
		for(; pos != end; ++pos) {
			cout << "Matched: " << pos->str() << endl;
		}
	}

	return 0;
}
