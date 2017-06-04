//use -g flag with compiler and info registers to check registers status while debugging with gdb
#include <iostream>
using namespace std;

int main(void) {

	__asm__(
				"movl $10, %eax;"
				"movl $20, %ebx;"
				"addl %ebx, %eax;"
			);
	
	__asm__(
				"movl $10, %eax;"
				"movl $20, %ebx;"
				"subl %ebx, %eax;"
			);

	__asm__(
				"movl $10, %eax;"
				"movl $20, %ebx;"
				"imull %ebx, %eax;"
			);

	return 0;
}
