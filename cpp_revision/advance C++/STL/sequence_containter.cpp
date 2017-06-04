#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <algorithm>
#include <iterator>
#define pb push_back
using namespace std;

int main(void) {

	vector<int> vec;
	vec.pb(4);
	vec.pb(1);
	vec.pb(8);
	vector<int>::iterator itr1 = vec.begin();
	vector<int>::iterator itr2 = vec.end();
	for(vector<int>::iterator itr = itr1; itr != itr2; ++itr)
		cout << *itr << " ";
	cout << endl;
	vec.insert(vec.begin() + 2, 2);
	sort(vec.begin(), vec.end(), [](int a, int b){return a > b; });
	for(auto i : vec)
		cout << i << " ";
	cout << endl;

	deque<int> deq;
	deq.push_back(4);
	deq.push_back(5);
	deq.push_front(3);
	deque<int>::iterator itD1 = deq.begin();
	deque<int>::iterator itD2 = deq.end();
	for(deque<int>::iterator itD = itD1; itD != itD2; ++itD)
		cout << *itD << " ";
	cout << endl;
	deq.insert(deq.begin() + 2, 2);
	sort(deq.begin(), deq.end(), [](int a, int b){return a > b; });
	for(auto i : deq)
		cout << i << " ";
	cout << endl;

	list<int> lst;
	list<int> lst2 {1, 2, 3, 4, 5};
	lst.push_back(4);
	lst.push_back(5);
	lst.push_front(2);
	list<int>::iterator itL1 = lst.begin();
	list<int>::iterator itL2 = lst.end();
	for(list<int>::iterator itL = itL1; itL != itL2; ++itL)
		cout << *itL << " ";
	cout << endl;
	itL1 = find(lst.begin(), lst.end(), 4);
	lst.insert(itL1, 7);
	lst.splice(itL1, lst2, lst2.begin(), lst2.end());
	for(auto i : lst)
		cout << i << " ";
	cout << endl;

	forward_list<int> fw;
	forward_list<int>::iterator itF1 = fw.before_begin();
	forward_list<int>::iterator itF2 = fw.end();
	itF1 = fw.insert_after(itF1, {1, 2, 3});
	itF1 = fw.insert_after(itF1, {1, 2, 3});
	itF1 = fw.insert_after(itF1, {1, 2, 3});
	// for(auto i : fw)
	//     cout << i << " ";
	for(forward_list<int>::iterator it = fw.begin(); it != itF2; ++it)
		cout << *it << " ";
	cout << endl;

	array<int, 3> arr;
	arr.fill(5);
	for(auto i : arr)
		cout << i << " ";
	cout << endl;

	return 0;
}
