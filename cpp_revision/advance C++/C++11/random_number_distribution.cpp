#include <random>
#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

int main(void) {
	
	unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
	default_random_engine rng(seed);
	uniform_int_distribution<int> dist(0, 5);     //[0, 5]
	vector<int> vecI(20);
	for(int i = 0; i < 800; ++i) {
		int num = dist(rng);
		if(num >= 0 && num < 20)
			++vecI[num];
	}
	for(int i = 0; i < 20; ++i)
		cout << i << ": " << string(vecI[i], '*') << endl;	
	cout << endl;

	uniform_real_distribution<double> distR(0, 5); //[0, 5) 
	for(int i = 0; i < 10; ++i)
		cout << distR(rng) << " ";
	cout << endl;

	poisson_distribution<int> distP(1.0);		   //Mean
	vector<int> vecP(20);
	for(int i = 0; i < 800; ++i) {
		int num = distP(rng);
		if(num >= 0 && num < 20)
			++vecP[num];
	}
	for(int i = 0; i < 20; ++i)
		cout << i << ": " << string(vecP[i], '*') << endl;	
	cout << endl;

	normal_distribution<double> distN(10.0, 3.0);  //mean and standard deviation
	vector<int> vecN(20);
	for(int i = 0; i < 800; ++i) {
		int num = distN(rng); //convert double to int
		if(num >= 0 && num < 20)
			vecN[num]++;
	}

	for(int i = 0; i < 20; ++i)
		cout << i << ": " << string(vecN[i], '*') << endl;
	cout << endl;

	return 0;
}
