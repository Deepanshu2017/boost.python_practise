#include <iostream>
#include <functional>
#include <string>
#include <unordered_map>
using namespace std;

int main(void) {

	unordered_map<string, string> m;
	string s1, s2;
	m = {
		{"Pooja", "Tiwari"},
		{"Deepanshu", "Thakur"},
		{"Vaishali", "Sharma"},
		{"Jahnvi", "Kamra"}
	};
	cin >> s1 >> s2;
	m[s1] = s2;

	for(auto it = m.begin(); it != m.end(); ++it)
		cout << it->first << " " << it->second << endl;
	cout << m.bucket_count() << endl;
	hash<string> str_hash;
	cout << str_hash(s1) << endl;

	return 0;
}
