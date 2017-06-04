#include <iostream>
#include <chrono>
using namespace std;

int main(void) {

	chrono::steady_clock::time_point start = chrono::steady_clock::now();
	long long count = 0;
	for(int64_t i = 0; i < 123456789; ++i) {
		chrono::steady_clock::time_point start1 = chrono::steady_clock::now();
		++count;
	}
	cout << "temp: " << count << endl;
	for(int64_t i = 0; i < 123456789; ++i) {
		chrono::steady_clock::time_point start = chrono::steady_clock::now();
		--count;
	}
	cout << "temp: " << count << endl;
	chrono::steady_clock::time_point end = chrono::steady_clock::now();
	chrono::steady_clock::duration d = end - start;
	cout << "time elapsed: " << chrono::duration_cast<chrono::milliseconds>(d).count() << endl;
	return 0;
}
