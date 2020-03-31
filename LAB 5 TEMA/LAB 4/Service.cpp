#include "Service.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>

using namespace std;

Service::Service() {
	
}
Service::~Service() {
	
}

void Service::addCheltuiala(int nr, int suma, char* tip) {
	Cheltuiala c(nr, suma, tip);
	this->rep.addCheltuiala(c);
}

void Service::deleteCheltuiala(int nr) {
	this->rep.deleteCheltuiala(nr);
}
 

void Service::updateCheltuiala(int nr, char* old_tip, int new_nr, int new_suma, char* new_tip) {
	Cheltuiala c(new_nr, new_suma, new_tip);
	this->rep.updateCheltuiala(nr, old_tip , c);
}

Cheltuiala* Service::getAll() {
	return this->rep.getAll();
}

int Service::getSize() {
	return this->rep.getSize();
}

void Service::propCheltuieli(Cheltuiala cheltuieli[], int n, int nr, Cheltuiala result[], int& resultLen)
{
	resultLen = 0;
	for (int i = 0; i < n; i++)
	{
		if (cheltuieli[i].getNumar() == nr)
		{
			result[resultLen++] = cheltuieli[i];
		}
	}
}

int Service::sumaCheltuieli(Cheltuiala cheltuieli[], int n, char* tip)
{
	int sumCheltuieli = 0;
	for (int i = 0; i < n; i++)
		if (strstr(cheltuieli[i].getTip(),tip))
		{
			sumCheltuieli += cheltuieli[i].getSuma();
		}
			
	return sumCheltuieli;
}

void Service::filterCheltuieli(Cheltuiala cheltuieli[], int n, int suma, char* tip, Cheltuiala result[], int& resultLen)
{
	if (suma != 0)
	{
		resultLen = 0;
		for (int i = 0; i < n; i++)
		{
			if (cheltuieli[i].getSuma() < suma)
			{
				result[resultLen++] = cheltuieli[i];
			}
		}
	}
	else
	{
		resultLen = 0;
		for (int i = 0; i < n; i++)
		{
			if (strstr(cheltuieli[i].getTip(),tip))
			{
				result[resultLen++] = cheltuieli[i];
			}
		}

	}
}

void Service::delAll()
{
	this->rep.deleteCheltuieli();
}

void Service::undo(Cheltuiala history[],int n)
{
	this->rep.deleteCheltuieli(); 
	for (int i = 0; i < n; i++)
		rep.addCheltuiala(history[i]);

}