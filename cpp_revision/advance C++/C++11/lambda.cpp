#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int main(void) {

	int x = 4;
	auto y = [&r = x, var = x + 1]() -> int {
		r += 2;
		return var + 2;
	}();
	cout << x << " " << y << endl;
	return 0; 
}
