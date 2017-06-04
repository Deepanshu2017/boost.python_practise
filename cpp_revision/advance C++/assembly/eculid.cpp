#include <bits/stdc++.h>
using namespace std;

int gcd(int var1, int var2) {
	int result = 0;
	__asm__ __volatile__ (
				"movl %1, %%eax\n\t"
				"movl %2, %%ebx\n\t"
				"CONTD%=:\n\t"
				"cmpl $0, %%ebx\n\t"
				"je DONE%=\n\t"
				"xorl %%edx, %%edx\n\t"
				"idivl %%ebx\n\t"
				"movl %%ebx, %%eax\n\t"
				"movl %%edx, %%ebx\n\t"
				"cmpl $0, %%ebx\n\t"
				"jne CONTD%=\n\t"
				"DONE%=:"
				"movl %%eax, %0\n\t"
				:"=r"(result)
				:"r"(var1), "r"(var2)
				:"%eax", "%ebx", "%edx"
			);
	return result;
}

int main(void) {

	int first = 0, second = 0;
	cin >> first >> second;
	clock_t start = clock();
	for(int i = 0; i < 1234; ++i)
		cout << "GCD is: " << gcd(first, second) << endl;
	clock_t end = clock();
	cout << "time taken: " << (double)(end - start) * 1000 / CLOCKS_PER_SEC << endl;
	return 0;
}
