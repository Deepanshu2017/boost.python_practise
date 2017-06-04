#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
using namespace std;

int main(int argc, char** argv) {

	vector<int> vec = {9, 60, 90, 8, 45, 87, 90, 69, 69, 55, 7};
	cout << count(vec.begin(), vec.end(), 69) << endl;
	cout << count_if(vec.begin(), vec.end(), [](int x) { return x == 69; } ) << endl;
	cout << *max_element(vec.begin(), vec.end()) << endl;
	cout << *max_element(vec.begin(), vec.end(), [](int x, int y) { return x < y; } ) << endl;
	cout << *min_element(vec.begin(), vec.end(), [](int x, int y) { return x < y; } ) << endl;
	pair<vector<int>::iterator, vector<int>::iterator> p = minmax_element(vec.begin(), vec.end());
	cout << *p.first << " " << *p.second << endl;
	cout << *find(vec.begin(), vec.end(), 69) << endl;
	cout << *find_if(vec.begin(), vec.end(), [](int x) {return x == 69;}) << endl;
	cout << *find_if_not(vec.begin(), vec.end(), [](int x) {return x == 69;}) << endl;
	cout << *search_n(vec.begin(), vec.end(), 2, 69) << endl; // search n (in this case 2) concutive items in vec

	vector<int> sub = {45, 87, 90};
	cout << *search(vec.begin(), vec.end(), sub.begin(), sub.end()) << endl; // searchs for subrange or sub in vec
	cout << *find_end(vec.begin(), vec.end(), sub.begin(), sub.end()) << endl; //same as above but find from end of vec

	vector<int> items = {69, 87};
	cout << *find_first_of(vec.begin(), vec.end(), items.begin(), items.end()) << endl; // find any one item that matches from vec
	cout << *adjacent_find(vec.begin(), vec.end()) << endl; //find any two adjacent items

	vector<int> vec2 = {9, 60, 90, 8, 45, 87, 90, 69, 69, 55, 7};
	if(equal(vec.begin(), vec.end(), vec2.begin()))
		cout << "vec and vec2 are same" << endl;

	if(is_permutation(vec.begin(), vec.end(), vec2.begin()))
		cout << "vec is a permutation of vec2" << endl;

	if(is_sorted(vec.begin(), vec.end()))
		cout << "vec is sorted" << endl;
	else
		cout << "vec is not sorted" << endl;

	if(all_of(vec.begin(), vec.end(), [](int x) { if (x > 1) return 1; return 0; } ) )
		cout << "all items of vec is greater then 1" << endl;

	if(any_of(vec.begin(), vec.end(), [](int x) { if (x > 80) return 1; return 0; } ) )
		cout << "any item of vec is greater then 80" << endl;

	if(none_of(vec.begin(), vec.end(), [](int x) { if (x > 100) return 1; return 0; } ) )
		cout << "none of the items of vec is greater then 100" << endl;
	
	//see also
	//mismatch, lexicographical_compare, is_partitioned, is_heap, is_heap_untill

	return 0;
}
