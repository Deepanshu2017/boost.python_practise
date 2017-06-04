#ifndef __WRAPPER_H
#define __WRAPPER_H
#ifdef __cplusplus
extern "C" {
#endif
	
	typedef struct Girl Girl;
	void* createGirl();
	void destroyGirl(void*);
	void my_setter(void* g, int var);
	int my_getter(void*g);

#ifdef __cplusplus	
}
#endif
#endif
