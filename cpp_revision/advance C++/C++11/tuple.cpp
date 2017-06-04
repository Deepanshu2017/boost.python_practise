#include <iostream>
#include <string>
#include <tuple>
using namespace std;

int main(void) {

	tuple<int, string, char> t(32, "Pooja", 'D');
	cout << get<0>(t) << endl;
	cout << get<1>(t) << endl;
	cout << get<2>(t) << endl;

	string& ref = get<1>(t);
	ref = "Pooja Tiwari";
	cout << get<0>(t) << endl;
	cout << get<1>(t) << endl;
	cout << get<2>(t) << endl;

	tuple<int, string, char> t2, t3;
	t2 = tuple<int, string, char>(12, "Pooja", 'D');
	t3 = make_tuple(12, "Deepanshu", 'p');
	if(t > t2) {	//lexicographical comparison
		cout << "t is larger then t2" << endl;
	}
	t3 = t2;	//member by member copy
	string st = "Pooja";
	tuple<string&> t4(st);
	get<0>(t4) = "Pooja Tiwari";
	cout << st << endl;

	int x;
	string y;
	char z;
	tie(x, y, z) = t2;
	y = "Deepanshu";
	cout << y << " " << get<1>(t2) << endl;

	auto t5 = tuple_cat(t, t2, t3, t4);

	cout << tuple_size<decltype(t5)>::value << endl;
	tuple_element<1, decltype(t5)>::type d;

	return 0;
}
