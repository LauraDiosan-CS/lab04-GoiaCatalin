#pragma once
#include "Repo.h"
#include "Cheltuiala.h"

class Service {
private:
	Repo rep;
public:
	Service();
	~Service();
	void addCheltuiala(int nr, int suma, char* tip);
	void deleteCheltuiala(int nr);
	void updateCheltuiala(int nr, char* old_tip, int new_nr, int new_suma, char* new_tip);
	Cheltuiala* getAll();
	int getSize();
	void propCheltuieli(Cheltuiala cheltuieli[], int n, int nr, Cheltuiala result[], int& resultLen);
	int sumaCheltuieli(Cheltuiala cheltuieli[], int n,char* tip);
	void filterCheltuieli(Cheltuiala cheltuieli[], int n, int suma,char *tip, Cheltuiala result[], int& resultLen);
	void delAll();
	void undo(Cheltuiala history[],int n);
};