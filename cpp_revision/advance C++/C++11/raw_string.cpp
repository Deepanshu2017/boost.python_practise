#include <bits/stdc++.h>
using namespace std;

int main(void) {

	const char* a = u8"UTF-8 string";
	const char16_t* b = u"UTF-16 string";
	const char32_t* c = U"UTF-32 string";
	const char* d = R"DELIM((Raw%\b \ \\ string\n)DELIM";
	cout << a << endl;
	cout << b << endl; //my terminal does not support UTF-16 and UTF-32
	cout << c << endl; //so some pointer location will be printed here
	cout << d << endl;

	return 0;
}
