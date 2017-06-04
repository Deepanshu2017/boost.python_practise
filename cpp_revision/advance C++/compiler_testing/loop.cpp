#include <iostream>

int main(void) {

	int i = 1;
	long long j = 0;
	for(; i < 123456789; ++i) {
		if(i % 2)
			j += 123;
		else
			j = j * i * j * 12 / 1234;
		std::cout << i << " " << j << std::endl;
	}

	return 0;
}
