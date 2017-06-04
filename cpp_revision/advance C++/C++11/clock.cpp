#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int main(void) {

	ratio<1, 10> r1;
	ratio<2, 10> r2;
	cout << r1.num << "/" << r1.den << endl;
	cout << r2.num << "/" << r2.den << endl;
	cout << system_clock::period::num << "/" << system_clock::period::den << endl;

	microseconds mi(2700);
	nanoseconds na = mi;
	milliseconds mill = duration_cast<milliseconds>(mi);
	
	mi = mill + mi;
	cout << mi.count() << endl;

	system_clock::time_point tp = system_clock::now();
	cout << tp.time_since_epoch().count() << endl;
	tp = tp + seconds(2);
	cout << tp.time_since_epoch().count() << endl;

	steady_clock::time_point start = steady_clock::now();
	cout << "Pooja" << endl;
	steady_clock::time_point end = steady_clock::now();
	steady_clock::duration d = end - start;
	if(d == steady_clock::duration::zero())
		cout << "no time elapsed" << endl;
	cout << duration_cast<nanoseconds>(d).count() << endl;

	chrono::steady_clock::time_point start1 = chrono::steady_clock::now();
	printf("Pooja\n");
	chrono::steady_clock::time_point end1 = chrono::steady_clock::now();
	chrono::steady_clock::duration d1 = end1 - start1;
	cout << "time elapsed: " << chrono::duration_cast<chrono::nanoseconds>\
		(d1).count() << endl;

	return EXIT_SUCCESS;
}
