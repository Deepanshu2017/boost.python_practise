#include "mylib.h"
#include <stdio.h>

int main(void) {
	Data *data = getData();
	storeData(data, 10);
	printf("Value is: %d\n", doSomeThing(data));
	freeData(data);
	return 0;
}
