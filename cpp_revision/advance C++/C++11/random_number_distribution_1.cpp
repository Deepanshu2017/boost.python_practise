#include <random>
#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char** argv) {

	//***********************************************************************//
	// unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
	// default_random_engine rng(seed);
    //
	// // If I want to generate number in between [0, 5]
	// cout << rng() % 6 << endl;
	// // 1. Bad quality of randomness
	// // 2. Can only provide uniform distribution
	//
	// uniform_int_distribution<int> distI(0, 5); //range [0, 5]
	// cout << distI(rng) << endl;
    //
	// uniform_real_distribution<double> distR(0, 5); //range [0, 5)
	// cout << distR(rng) << endl;
    //
	// poisson_distribution<int> distP(1.0); //mean 
	// cout << distP(rng) << endl;
    //
	// cout << "normal distribution: " << endl;
	// normal_distribution<double> distN(10.0, 3.0); //mean and standard deviation
	// vector<int> vec(20);
	// for(int i = 0; i < 800; ++i) {
	// 	int num = distN(rng); //convert double to int
	// 	if(num >= 0 && num < 20)
	// 		vec[num]++; //record the frequency of number
	// }
    //
	// for(int i = 0; i < 20; ++i) {
	// 	cout << i << ": " << string(vec[i], '*') << endl;
	// }
	// cout << endl;

	//***********************************************************************//

	// int count = 0, trials = 10000;
	// unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
	// default_random_engine rng(seed);
	// bernoulli_distribution dist(0.9);
	// for(int i = 0; i < trials; ++i)
	// 	if(dist(rng))
	// 		++count;
    //
	// cout << "bernoulli distribution (0.9) * 10000:" << endl;
	// cout << "true: " << count << endl;
	// cout << "false: " << trials - count << endl;
    //
	// cout << endl;
    //
	// count = 0;
	// seed = chrono::steady_clock::now().time_since_epoch().count();
	// rng.seed(seed);
	// bernoulli_distribution dist2(0.001);
	// for(int i = 0; i < trials; ++i)
	// 	if(dist2(rng))
	// 		++count;
    //
	// cout << "bernoulli distribution (0.001) * 10000:" << endl;
	// cout << "true: " << count << endl;
	// cout << "false: " << trials - count << endl;
	// cout << "min: " << dist2.min() << endl;
	// cout << "max: " << dist2.max() << endl;
	// cout << "p: " << dist2.p() << endl;

	//***********************************************************************//
	
	// random_device rd;
	// default_random_engine rng(rd());
	// // binomial_distribution<> dist(4, 0.5);
	// binomial_distribution<> dist(1, 0.5);
	// bernoulli_distribution dist2(0.5);
	// map<int, int> hist;
	// for(int i = 0; i < 10000; ++i)
	// 	++hist[dist(rng)];
	//
	// for(auto p : hist)
	// 	cout << p.first << ' ' << p.second << endl;
    //
	// hist.clear();
	// cout << endl;
    //
	// for(int i = 0; i < 10000; ++i)
	// 	++hist[dist2(rng)];
	//
	// for(auto p : hist)
	// 	cout << p.first << ' ' << p.second << endl;
	
	//***********************************************************************//

	// random_device rd;
	// cout << rd() << endl;
	// cout << rd.entropy() << endl; //0 means no random device avaliable
	
	//***********************************************************************//

	//normal distribution (produces bell shaped curve)
	//parameter of constructor mean and standard deviation
	//mean is the centre value of the bell
	//standard deviation (how spread the data is)
	//standard deviation is the sqrt of the Variance
	//Variance is the average of the squared difference from the mean
	//let's see an example
	//data is 600, 470, 170, 430, 300
	//mean 600 + 470 + 170 + 430 + 300 / 5 = 394
	//variance is (206^2) + (76^2) + (-224^2) + (36^2) + (-94^2) / 5 = 21704
	//standard deviation is sqrt(21704) = 147.32
	//see example at https://www.mathisfun.com/data/standard-deviation.html
	// random_device rd;
	// default_random_engine rng(rd());
	// normal_distribution<double> dist(5.0, 2.0);
	// map<int, int> hist;
	// for(int i = 0; i < 10000; ++i) {
	// 	++hist[(int)dist(rng)];
	// }
	// for(auto p : hist)
	// 	cout << p.first << ' ' << p.second << endl;

	//***********************************************************************//
	
	// random_device rd;
	// mt19937 rng(rd());
	// // mt19937_64 rng(rd());
	// cout << rng() << endl;

	//***********************************************************************//

	random_device rd;
	mt19937_64 rng(rd());
	poisson_distribution<int> dist(5.0); //mean
	int p[10] = {[0 ... 9] = 0};
	for(int i = 0; i < 10000; ++i) {
		int num = dist(rng);
		if(num < 10)
			++p[num];
	}

	for(int i = 0; i < 10; ++i)
		cout << i << ": " << p[i] << ' ' << endl;

	return 0;
}
