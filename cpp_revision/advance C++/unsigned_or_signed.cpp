#include <iostream>

int main(void) {
	int i = -10;
	unsigned j = 42;
	//when performing operations which takes both signed and
	//unsigned integers then signed int is converted into unsigned
	//then perform the arthematic operation
	std::cout << i + i << std::endl;
	std::cout << j + j << std::endl;
	std::cout << i + j << std::endl;
	return 0;
}
