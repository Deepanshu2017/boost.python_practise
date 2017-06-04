#include <iostream>
#include <regex>
using namespace std;

int main(int argc, char** argv) {

	string str;
	cin >> str;
	string str2;
	cin >> str2;
	regex reg("([[:w:]]+)@([[:w:]]+)\\.com");
	cout << regex_replace(str, reg, str2) << endl;
	
	return 0;
}
