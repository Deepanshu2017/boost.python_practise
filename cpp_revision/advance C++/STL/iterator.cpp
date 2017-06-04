#include <iostream>
#include <iterator>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main(void) {

	// vector<int> vec = {1, 2, 3, 5, 7, 6, 4, 8};
	// vector<int>::iterator it = find(vec.begin(), vec.end(), 5);
	// cout << *it << endl;
	// advance(it, 3);
	// cout << *it << endl;
	// cout << distance(vec.begin(), it) << endl;

	//****************************************************//
	
	// vector<int> vec1 = {4, 5};
	// vector<int> vec2 = {12, 14, 16, 18};
	// vector<int>::iterator it = find(vec2.begin(), vec2.end(), 16);
	// insert_iterator<vector<int> > i_itr(vec2, it);
	// // copy(vec1.begin(), vec1.end(), i_itr);
	// // back_insert_iterator<vector<int> > b_itr(vec2);
	// // copy(vec1.begin(), vec1.end(), b_itr);
	// deque<int> deq;
	// front_insert_iterator<deque<int> > f_itr(deq);
	// copy(vec2.begin(), vec2.end(), f_itr);
	// for(auto i : deq)
	// 	cout << i << " ";
	// cout << endl;

	//****************************************************//
	
	// vector<string> vec;
	// // copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(vec));
	// //	both line are same
	// back_insert_iterator<vector<string> > itr(vec);
	// copy(istream_iterator<string>(cin), istream_iterator<string>(), itr);
	// //represents the end of the stream or iterator ------^
	// copy(vec.begin(), vec.end(), ostream_iterator<string>(cout, " "));
	//
	// //Even more shorter version
	// copy(istream_iterator<string>(cin), istream_iterator<string>(), ostream_iterator<string>(cout, " "));

	//****************************************************//
	
	vector<int> vec = {2, 4, 6, 7, 3, 8};
	auto it = find_if(vec.begin(), vec.end(), [](int var){ return var % 2; });
	cout << *it << endl;

	return 0;
}
