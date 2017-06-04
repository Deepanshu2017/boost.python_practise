#include <iostream>
using namespace std;

//Userdefined literals can work with only these types of parameters
//char const*
//unsigned long long
//long double
//char const*, size_t
//wchar_t, size_t
//char16_t, size_t
//char32_t, size_t
//return value can be of any type

constexpr long double operator"" _cm(long double x) { return x * 10; }
constexpr long double operator"" _m(long double x) { return x * 1000; }
constexpr long double operator"" _mm(long double x) { return x; }

constexpr int operator"" _bin(const char* str, size_t len) {
	int ret = 0;
	for(int i = 0; i < len; ++i) {
		ret = ret << 1;
		if(str[i] == '1')
			ret += 1;
	}
	return ret;
}

int main(void) {
	
	long double height = 3.4_cm;
	cout << height << endl;
	cout << (height + 13.0_m) << endl;	
	cout << "110"_bin << endl;
	
	
	return 0;
}