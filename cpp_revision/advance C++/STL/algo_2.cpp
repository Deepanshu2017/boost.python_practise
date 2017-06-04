#include <iostream>
#include <vector>
#include <utility>
#include <iterator>
#include <algorithm>
#include <random>
using namespace std;

void clear(vector<int>& v) {
	v.clear();
	v.resize(10);
	return;
}

void traverse(const vector<int>& v) {
	for(auto i : v)
		cout << i << " ";
	cout << endl;
}

void perform(vector<int>& v) {
	traverse(v);
	clear(v);
}

int main(int argc, char** argv) {

	vector<int> vec1 = {9, 60, 70, 8, 45, 87, 90};
	vector<int> vec2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	vector<int>::iterator it1, it2;
	pair<vector<int>::iterator, vector<int>::iterator> p;
	copy(vec1.begin(), vec1.end(), vec2.begin());

	perform(vec2);	

	copy_if(vec1.begin(), vec1.end(), vec2.begin(), [](int x) { return x > 60;});
	perform(vec2);	

	copy_n(vec1.begin(), 5, vec2.begin());
	perform(vec2);	

	copy_backward(vec1.begin(), vec1.end(), vec2.end());
	perform(vec2);	

	transform(vec1.begin(), vec1.end(), vec2.begin(), [](int x) { return 10; });
	perform(vec2);

	vector<int> vec3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3};
	transform(vec1.begin(), vec1.end(), vec3.begin(), vec2.begin(), [](int x, int y) { return x + y; });
	perform(vec2);

	swap_ranges(vec1.begin(), vec1.end(), vec2.begin());
	perform(vec1);
	perform(vec2);

	fill(vec1.begin(), vec1.end(), 10);
	perform(vec1);

	fill_n(vec1.begin(), 5, 20);
	perform(vec1);

	random_device rd;
	mt19937_64 rng(rd());
	uniform_int_distribution<int> dist(10, 20);
	generate(vec1.begin(), vec1.end(), rng);
	perform(vec1);

	replace(vec1.begin(), vec1.end(), 0, 6);
	perform(vec1); //generalized form replace_if

	vec1[1] = 5; vec1[6] = 8;
	replace_copy(vec1.begin(), vec1.end(), vec2.begin(), 0, 6);
	perform(vec1);
	perform(vec2); //generalized form replace_copy_if

	remove(vec1.begin(), vec1.end(), 0);
	perform(vec1); //remove_if, remove_copy, remove_copy_if

	vec1 = {1, 2, 3, 3, 4, 5, 3, 5, 4, 9};
	unique(vec1.begin(), vec1.end()); //remove consecutive same elements
	perform(vec1); //unique_copy

	vec1 = {1, 2, 3, 3, 4, 5, 3, 5, 4, 9};
	reverse(vec1.begin(), vec1.end());
	perform(vec1); //reverse_copy

	vec1 = {1, 2, 3, 3, 4, 5, 3, 5, 4, 9};
	rotate(vec1.begin(), vec1.begin() + 3, vec1.end()); //rotate 3 times
	perform(vec1); //rotate_copy

	vec1 = {1, 2, 3, 3, 4, 5, 3, 5, 4, 9};
	next_permutation(vec1.begin(), vec1.end());
	perform(vec1);

	vec1 = {1, 2, 3, 3, 4, 5, 3, 5, 4, 9};
	prev_permutation(vec1.begin(), vec1.end());
	perform(vec1);

	vec1 = {1, 2, 3, 3, 4, 5, 3, 5, 4, 9};
	random_shuffle(vec1.begin(), vec1.end());
	perform(vec1);

	vec1 = {1, 2, 3, 3, 4, 5, 3, 5, 4, 9};
	shuffle(vec1.begin(), vec1.end(), rng);
	perform(vec1);

	return 0;
}
