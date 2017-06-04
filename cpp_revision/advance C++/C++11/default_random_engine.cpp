#include <bits/stdc++.h>
using namespace std;

void print(default_random_engine rng) {
	for(int i = 0; i < 10; ++i)
		cout << rng() << " ";
	cout << endl;
}

int main(void) {

	/*
	default_random_engine rng1;
	cout << "minimum is: " << rng1.min() << endl;
	cout << "maximum is: " << rng1.max() << endl;
	print(rng1);
	stringstream state;
	state << rng1;

	print(rng1);
	state >> rng1;
	print(rng1);
	*/

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	default_random_engine rng(seed);
	unsigned seed2 = std::chrono::system_clock::now().time_since_epoch().count();
	default_random_engine rng2(seed2);
	print(rng);
	print(rng2);

	rng.seed(); 	//reset to initial state
	print(rng);
	rng2.seed();
	print(rng2);
	if(rng == rng2)
		cout << "both are printing same values" << endll

	return 0;
}
