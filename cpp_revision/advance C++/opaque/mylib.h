#ifndef __MYLIB_H
#define __MYLIB_H

typedef struct Data Data;
void* getData();
void freeData(Data*);
int doSomeThing(Data*);
void storeData(Data*, int);

#endif
