//some build-in functors
//less, greater, less_equal, greater_equal, not_equal_to,
//logical_and, logical_not, logical_or,
//multiplies, minus, plus, divide, modulus, negate
//Predicate:
//1. Returns a boolean
//2. Does not modify data
//Parametrized functions(functors)
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <deque>
#include <algorithm>
#include <set>
#include <iterator>
#include <functional>
using namespace std;

class X {
	string name = "Pooja Tiwari";
	public:
		X() = default;
		X(string name) {
			cout << "I am in constructor: " << name << endl;
		}
		void operator()(string str) const {
			cout << "I love " << str << endl;
		}
		operator string() const {
			return string("I love " + name);
		}
};

void add2(int i) { cout << i + 2 << " "; }

template<int val>
void addVal(int i) { cout << i + val << " "; }

class addValue {
	private:
		int val = 0;
	public:
		addValue(int val) : val(val) {}
		void operator() (int i) { cout << i + val << " "; }
};

void addValTemp(int i, int val) {
	cout << i + val << endl;
}

double pow_(double var1, double var2) {
	return var1 * var2;
}

int main(void) {

	X("Pooja")("Pooja Tiwari");
	X foo("Pooja Tiwari");
	string str = foo;
	cout << str << endl;

	vector<int> vec = {2, 3, 4, 5};
	for_each(vec.begin(), vec.end(), add2);
	cout << endl;
	for_each(vec.begin(), vec.end(), addVal<2>);
	cout << endl;
	for_each(vec.begin(), vec.end(), addValue(2));
	
	int x = multiplies<int>()(3, 4);
	if(not_equal_to<int>()(x, 10))
		cout << x << endl;

	set<int> s = {2, 3, 4, 5};
	vector<int> vec2;
	back_insert_iterator<vector<int> > b_itr(vec2);
	// transform(s.begin(), s.end(), back_inserter(vec2), 
	// 		bind(multiplies<int>(), placeholders::_1, 10)
	// 	);

	transform(s.begin(), s.end(), b_itr, \
			bind(multiplies<int>(), placeholders::_1, 10));

	for(auto i : vec2)
		cout << i << " ";
	cout << endl;

	int my_var = 5;
	for_each(vec2.begin(), vec2.end(), bind(addValTemp, placeholders::_1, my_var));
	for(auto i : vec2)
		cout << i << " ";
	cout << endl;

	deque<int> d;
	// auto f = function<double (double, double)>(pow_);
	auto f = pow_;
	transform(vec2.begin(), vec2.end(), front_inserter(d), bind(f, placeholders::_1, 7));

	for(auto i : d)
		cout << i << " ";
	cout << endl;


	set<int> _pset;
	deque<int> _pdeq;
	
	mt19937 rng;
	rng.seed(random_device()());
	uniform_int_distribution<> uni(123, 456);
	for(int i = 0; i < 12; ++i) {
		_pset.insert(uni(rng));
	}

	//What I want to do is (x > 200) || (x < 300) copy from _pset to _pdeq
	transform(_pset.begin(), _pset.end(), front_inserter(_pdeq),
			bind(logical_or<bool>(), 
				bind(greater<int>(), placeholders::_1, 200),
				bind(less<int>(), placeholders::_1, 300)
			)
		);
	for(auto i : _pset)
		cout << i << " ";
	cout << endl;
	for(auto i : _pdeq)
		cout << i << " ";
	cout << endl;

	return 0;
}
