#include <bits/stdc++.h>
using namespace std;

int main(void) {

	string str;
	int i = 5;
	while(i--) {
		cin >> str;
		// regex e("abc.", regex_constants::icase);
		// regex e("abc?", regex_constants::icase);
		// regex e("abc*", regex_constants::icase);
		// regex e("abc+", regex_constants::icase);
		// regex e("ab[cd]*", regex_constants::icase);
		// regex e("ab[^cd]*", regex_constants::icase);
		// regex e("ab[cd]{3}", regex_constants::icase);
		// regex e("ab[cd]{3,}", regex_constants::icase);
		// regex e("abc|de[fg]", regex_constants::icase);
		// regex e("abc|de[\]fg")}}", regex_constants::icase";
		// regex e("(abc)de+\\1");
		// regex e("(ab)c(de+)\\2\\1");
		// regex e("[[:w:]]+@[[:w:]]+\.com") ;
		// regex e("[[:alnum:]]");
		// see all predefined character classes from C++.com
		// bool match = regex_match(str, e);
		// regex e("^abc.", regex_constants::icase);
		//   -------^---> search at the beginning of the text only
		// regex e("abc.$", regex_constants::icase);
		// -------------^---> search at the end of the text only
		regex e("^abc.$", regex_constants::icase);
		bool match= regex_search(str, e);
		cout << (match ? "Matched" : "Not Matched") << endl;
	}

	return 0;
}
