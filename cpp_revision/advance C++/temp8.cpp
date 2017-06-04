#include <iostream>
using namespace std;
#define POOJA cout << "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP" << endl;

void NOMOREMEORY() {
	cout << "WHAT THE FUCK" << endl;
	POOJA
	exit(1);
}

void* operator new(size_t size) throw (bad_alloc) {
	cout << "I am in my custom new" << endl;
	void *p = malloc(size);
	if(p)
		return p;
	 new_handler Handler = set_new_handler(0);
	 if(Handler)
		 (*Handler)();
	 else
		 throw bad_alloc();
}

int main(void) {

	set_new_handler(NOMOREMEORY);
	int *pt = new int[100000000];
	for(int i = 0; i < 100000000; ++i)
		pt[i] = 1;
	for(int i = 0; i < 100000000; ++i)
		cout << i[pt] << " ";
	delete pt;

	return 0;
}
