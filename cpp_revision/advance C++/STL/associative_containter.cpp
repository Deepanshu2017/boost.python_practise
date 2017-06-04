//In sequence containers there are  no member function find()
//In associative containers there are no member function push_back or
//push_front
//No sequence container provide functionality of erase member method
//as provided by set

//In set and multiset value is read only
//we cannot modify it through iterator or pointer or refrence
//In map and multimap key once assigned cannot be changed again

#include <iostream>
#include <set>
#include <map>
#include <string>
#include <iterator>
#include <utility>
using namespace std;

template<typename sets>
void traverse(const sets &s) {
	for(auto it = s.cbegin(); it != s.cend(); ++it)
		cout << *it << " ";
	cout << endl;
}


// void traverse(const multiset<int> &s) {
// 	for(auto it = s.cbegin(); it != s.cend(); ++it)
// 		cout << *it << " ";
// 	cout << endl;
// }

template<typename maps>
void traverse2(const maps &s) {
	for(auto it = s.cbegin(); it != s.cend(); ++it)
		cout << it->first << " " << (*it).second << endl;
}

int main(int argc, char** argv) {

	set<int> s;
	set<int>::iterator it;
	s.insert(5);
	s.insert(3);
	s.insert(2);
	s.insert(4);
	s.insert(1);
	// s ==> {1, 2, 3, 4, 5}
	pair<set<int>::iterator, bool> res;
	res = s.insert(3);
	if(!res.second)
		it = res.first; //it is pointing to 3

	s.insert(it, 9); // s ==> {1, 2, 3, 4, 5, 9}; it points to 3
					 // In above case insertion time O(log(n)) => O(1)
	s.erase(it);	 // 3 is erased s ==> {1, 2, 4, 5, 9}
	s.erase(9);		 // 9 is erased s ==> {1, 2, 4, 5}

	traverse(s);


	multiset<int> multi;
	multiset<int>::iterator itM;
	multi.insert(1);
	multi.insert(1);
	multi.insert(2);
	multi.insert(2);
	multi.insert(3);
	multi.insert(3);
	multi.insert(4);
	multi.insert(4);
	
	traverse(multi);
	itM = multi.find(4);
	// *itM = 10; //itM is readonly

	map<char, string> m;
	m.insert(pair<char, string>('p', "Pooja"));
	m.insert(make_pair('d', "Deepanshu"));
	m.insert({'t', "Tiwari"});
	traverse2(m);
	cout << "**************************************" << endl;

	multimap<char, string> mm;
	mm.insert(pair<char, string>('p', "Pooja"));
	mm.insert(pair<char, string>('p', "Pooja"));
	mm.insert(make_pair('d', "Deepanshu"));
	mm.insert(make_pair('d', "Deepanshu"));
	traverse2(mm);

	return 0;
}
