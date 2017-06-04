//unordered set/multiset ==> key cannot be changed
//unordered map/multimap ==> key cannot be changed

#include <iostream>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <utility>
#include <string>
using namespace std;

template<typename T>
void traverse(const T &s) {
	for(auto it = s.cbegin(); it != s.cend(); ++it)
		cout << *it << " ";
	cout << endl;
}

template<typename T>
void traverse2(const T &m) {
	for(auto it = m.cbegin(); it != m.cend(); ++it)
		cout << it->first << " " << it->second << endl;
}

int main(int argc, char** argv) {

	unordered_set<string> s = {"Pooja", "Deepanshu"};
	s.insert("Vaishali");
	vector<string> vec = {"Anshu", "Jahnvi"};
	s.insert(vec.begin(), vec.end());
	traverse(s);

	cout << "load factor is: " << s.load_factor() << " elements:buckets\n";
	string p = "Pooja";
	cout << p << " is in bucket #: " << s.bucket(p) << endl;
	cout << "Total bucket #: " << s.bucket_count() << endl;

	cout << "****************************" << endl;

	unordered_multiset<string> us = {"Pooja", "Pooja", "Pooja"};
	traverse(us);
	cout << "load factor is: " << s.load_factor() << " elements:buckets\n";
	cout << p << " is in bucket #: " << s.bucket(p) << endl;
	cout << "Total bucket #: " << s.bucket_count() << endl;

	cout << "****************************" << endl;

	unordered_map<char, string> m;
	m.insert({'p', "Pooja"});
	m.insert({'v', "Vashu"});
	m.insert({'d', "Deepu"});
	traverse2(m);
	cout << "load factor is: " << s.load_factor() << " elements:buckets\n";
	cout << p << " is in bucket #: " << s.bucket(p) << endl;
	cout << "Total bucket #: " << s.bucket_count() << endl;

	cout << "****************************" << endl;

	unordered_multimap<char, string> mm;
	m.insert({'p', "Pooja"});
	m.insert({'p', "Pooja"});
	m.insert({'p', "Pooja"});
	traverse2(m);
	cout << "load factor is: " << s.load_factor() << " elements:buckets\n";
	cout << p << " is in bucket #: " << s.bucket(p) << endl;
	cout << "Total bucket #: " << s.bucket_count() << endl;

	hash<string> h;
	cout << h("Pooja") << endl;

	return 0;
}
