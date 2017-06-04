#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <utility>
#include <random>
#include <chrono>
#include <type_traits>
using namespace std;

string& refrence(string& st) {
	return st;
}

int& get_i() {
	static int my_var = 5;
	return my_var;
}

int main(int argc, char** argv) {

	pair<int, string> p = {21, "Deepanshu"};
	pair<int, string> p_2 =make_pair(20, "Pooja");
	cout << p.first << " " << p.second << endl;
	cout << p_2.first << " " << p_2.second << endl;
	
	tuple<int, string, char> t(20, "Pooja Tiwari", 'P');
	cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
	get<2>(t) = 'P';
	cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
	char& ref = get<2>(t);
	ref = 'T';
	cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
	
	int var = 1;
	// cout << get<var>(t) << endl; // var must be compile time constant
	// else the above code will not compile
	
	const auto var_2 = 1;
	cout << get<var_2>(t) << endl;

	tuple<int, string, char> t_2;
	t_2 = make_tuple(21, "Deepanshu Thakur", 'D');
	if(t > t_2) //lexicographical comparison
		cout << "Pooja is bigger then Deepanshu" << endl;
	else
		cout << "Deepanshu is bigger then Pooja" << endl;

	t_2 = t; //member by member copy

	string y = "NULL";
	char z = '\0';
	tie(ignore, y, z) = t_2;
	cout << y << " " << z << endl;
	
	tuple<string&> t_3(y);
	auto t_4 = tuple_cat(t_2, t_3); //tuple of int, string, char, string&
	cout << tuple_size<decltype(t_4)>::value << endl; //4
	tuple_element<1, decltype(t_4)>::type d; //d is a string

	cout << endl << endl;
	auto i1 = get_i();
	decltype(get_i()) i2 = get_i();
	static_assert(is_same<decltype(i1), int>::value, "should not print");
	static_assert(is_same<decltype(i1), int&>::value, "it should print");
	static_assert(is_same<decltype(i2), int&>::value, "huh");

	return 0;
}
