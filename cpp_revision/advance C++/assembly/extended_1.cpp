#include <iostream>
using namespace std;

int main(void) {

	int var = 10;
	int var2 = 20;
	cout << "var: " << var << " var2: " << var2 << endl;
	__asm__(
				"movl %%edx, %%eax;"
				"movl %%ecx, %%ebx"
				:"=a"(var), "=b"(var2)
				:"c"(var), "d"(var2)
			);
	cout << "var: " << var << " var2: " << var2 << endl;
	return 0;
}
