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
	void updateCheltuiala(int nr, Cheltuiala c);
	Cheltuiala* getAll();
	int getSize();
};