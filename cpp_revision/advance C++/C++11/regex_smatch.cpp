#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main(void) {

	string str;
	int i = 5;
	while(i--) {
		cin >> str;
		smatch m;
		regex e("([[:w:]]+)@([[:w:]]+)\.com");
		bool found = regex_search(str, m, e);
		if(found) {
			cout << "size is: " << m.size() << endl;
			for(int it = 0; it < m.size(); ++it) {
				cout << m[it].str() << endl;
			}
			cout << "Prefix: " << m.prefix().str() << endl;
			cout << "Suffix: " << m.suffix().str() << endl;
		}
	}
	
	return 0;
}
