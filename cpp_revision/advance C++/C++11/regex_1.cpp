#include <iostream>
#include <regex>
using namespace std;

int main(void) {

	for(int i = 0; i < 5; ++i) {
		smatch m;
		string str;
		cin >> str;
		regex reg("([[:w:]]+)@([[:w:]]+)\\.com");
		bool match = regex_search(str, m, reg);
		cout << "m.size is: " << m.size() << endl;
		for(int i = 0; i < m.size(); ++i) {
			cout << m[i].str() << endl;
		}
		cout << "prefix is: " << m.prefix().str() << endl;
		cout << "suffix is: " << m.suffix().str() << endl;
	}

	return 0;
}
