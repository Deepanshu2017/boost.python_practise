#include "wrapper.h"
#include <stdio.h>

int main(int argc, char** argv) {

	/* struct Girl *g = createGirl(); */
	Girl *g = createGirl();
	my_setter(g, 5);
	printf("value is: %d\n", my_getter(g));
	destroyGirl(g);

	return 0;
}
