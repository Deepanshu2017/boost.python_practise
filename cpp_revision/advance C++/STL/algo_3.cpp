#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <deque>
#include <array>
using namespace std;

//only vector, array, deque can be sorted
// sort takes function not a functor

void print(const vector<int>& vec) {
	for(auto i : vec)
		cout << i << " ";
	cout << endl;
}

int main(int argc, char** argv) {

	vector<int> vec = {9, 10, 1, 2, 45, 3, 90, 4, 5, 9, 8};
	sort(vec.begin(), vec.end());
	print(vec);

	//sort only top 5 leave else
	vec = {9, 10, 1, 2, 45, 3, 90, 4, 5, 9, 8};
	partial_sort(vec.begin(), vec.begin() + 5, vec.end(), greater<int>());
	print(vec);

	cout << boolalpha << greater<int>()(6, 4) << endl;

	//find top 5 but don't sort these top 5 just put them in first top 5
	vec = {9, 10, 1, 2, 45, 3, 90, 4, 5, 9, 8};
	nth_element(vec.begin(), vec.begin() + 5, vec.end(), greater<int>());
	print(vec);

	//partiton vector into two parts
	struct local {
		static bool less_then_10(int x) {
			return x < 10;
		}
	};
	vec = {9, 10, 1, 2, 45, 3, 90, 4, 5, 9, 8};
	partition(vec.begin(), vec.end(), local::less_then_10);
	print(vec);

	vec = {9, 10, 1, 2, 45, 3, 90, 4, 5, 9, 8};
	stable_partition(vec.begin(), vec.end(), local::less_then_10); //preserves order
	print(vec);

	make_heap(vec.begin(), vec.end());
	pop_heap(vec.begin(), vec.end());
	vec.pop_back();
	print(vec);
	vec.push_back(100);
	push_heap(vec.begin(), vec.end());
	sort_heap(vec.begin(), vec.end());
	print(vec);

	return 0;
}
