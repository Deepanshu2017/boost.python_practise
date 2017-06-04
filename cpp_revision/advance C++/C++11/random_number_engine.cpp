#include <iostream>
#include <random>
#include <sstream>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;

void print(default_random_engine rng) {
	for(int i = 0; i < 10; ++i)
		cout << rng() << " ";
	cout << endl;
}

int main(int argc, char** argv) {

	// default_random_engine rng;
	// cout << "Min: " << rng.min() << endl;
	// cout << "Max: " << rng.max() << endl;
    //
	// cout << rng() << endl;
	// cout << rng() << endl;
    //
	// stringstream state;
	// state << rng;
    //
	// cout << rng() << endl;
	// cout << rng() << endl;
    //
	// state >> rng;
    //
	// cout << rng() << endl;
	// cout << rng() << endl;


	//**********************************************//

	default_random_engine rng1;
	default_random_engine rng2;

	print(rng1);
	print(rng2);

	unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	default_random_engine rng3(seed);
	print(rng3);

	rng3.seed(); //reset rng3 to initial state
	print(rng3);

	rng3.seed(123); //reset rng3 to the state accordingly
	print(rng3);

	rng1.seed(123);
	if(rng1 == rng3)
		cout << "rng1 and rng3 have the same state" << endl;

	rng3.seed(seed);
	vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	// shuffle(vec.begin(), vec.end(), default_random_engine());	
	shuffle(vec.begin(), vec.end(), rng3);	
	for(auto i : vec)
		cout << i << " ";
	cout << endl;

	return 0;
}
