#include "mylib.h"
#include "mylibint.h"
#include <stdlib.h>

void* getData() {
	return calloc(1, sizeof(Data));
}

void freeData(Data* data) {
	free(data);
}

int doSomeThing(Data* data) {
	return data->value;
}

void storeData(Data* data,int var) {
	data->value = var;
}
