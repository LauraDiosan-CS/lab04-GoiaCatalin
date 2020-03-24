#pragma once
#include "Repo.h"
#include "Cheltuiala.h"

class Service {
private:
	Repo rep;
public:
	Service();
	~Service();
	void addCheltuialaS(int nr, int suma, char* tip);
	void deleteCheltuialaS(int nr);
	void updateCheltuialaS(int nr, int new_nr, int new_suma, char* new_tip);
	Cheltuiala* getAll();
	int getSize();
};