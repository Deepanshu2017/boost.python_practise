#include "temp.h"
#include "wrapper.h"
#include <memory>

extern "C" {
	void* createGirl() {
		return new Pooja::Girl();
	}
	void destroyGirl(void* g) {
		delete static_cast<Pooja::Girl*>(g);
	}
	void my_setter(void* g, int var) {
		static_cast<Pooja::Girl*>(g)->setter(var);
	}
	int my_getter(void* g) {
		return static_cast<Pooja::Girl*>(g)->getter();
	}
}
