#pragma once
#include "Cheltuiala.h"

class Repo {
private:
	Cheltuiala cheltuieli[20];
	int n;
public:
	Repo();
	~Repo();
	void addCheltuiala(Cheltuiala c);
	void deleteCheltuiala(int nr);
	void deleteCheltuieli();
	void updateCheltuiala(int nr, char* tip, Cheltuiala c);
	Cheltuiala* getAll();
	int getSize();
};