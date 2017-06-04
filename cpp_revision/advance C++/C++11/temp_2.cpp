#include <iostream>
int main(void) {
	int i = 10;
	(i+=10)+=20;
	std::cout << i << std::endl;
}
