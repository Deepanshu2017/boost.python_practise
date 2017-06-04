#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {

	list<int> list_1 = {1, 2, 3, 10, 11};
	list<int> list_2 = {4, 5, 6, 7, 8, 9};
	list<int>::iterator itr_1 = find(list_1.begin(), list_1.end(), 3);
	list<int>::iterator itr_2_1 = find(list_2.begin(), list_2.end(), 4);
	list<int>::iterator itr_2_2 = find(list_2.begin(), list_2.end(), 9);
	list_1.splice(itr_1, list_2, itr_2_1, itr_2_2);

	cout << "list1: ";
	for(auto var : list_1)
		cout << var << " ";
	cout << endl;

	cout << "list2: ";
	for(auto var : list_1)
		cout << var << " ";
	cout << endl;

	list<int>::iterator itr_2_1_1 = find(list_2.begin(), list_2.end(), 4);
	if(itr_2_1_1 != list_2.end())
		cout << "iterator is valid" << endl;
	else
		cout << "iterator is not valid" << endl;

	for(auto var : list_1)
		cout << var << " ";
	cout << endl;

	for(auto var : list_1)
		cout << var << " ";
	cout << endl;

	return 0;
}
