#include "temp.h"
#include <iostream>

Pooja::Girl::Girl() { std::cout << "constructor of Girl\n"; }
Pooja::Girl::~Girl() { std::cout << "destructor of Girl\n"; }
void Pooja::Girl::setter(int var) { m_var = var; }
int Pooja::Girl::getter() { return m_var; }
