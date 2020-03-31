#include "Repo.h"

Repo::Repo() {
	this->n = 0;
}
Repo::~Repo() {
	this->n = 0;
}

void Repo::addCheltuiala(Cheltuiala c) {
	this->cheltuieli[this->n++] = c;
}
 
void Repo::deleteCheltuiala(int nr) {
	for (int i = 0; i < n; i++)
		if (this->cheltuieli[i].getNumar() == nr)
			for (int k = i; k < n - 1; k++)
				this->cheltuieli[k] = this->cheltuieli[k + 1];
	this->n--;
}

void Repo::deleteCheltuieli()
{
	this->n = 0;		
}

void Repo::updateCheltuiala(int nr, char* tip, Cheltuiala c) {
	for (int i = 0; i < n; i++)
		if (this->cheltuieli[i].getNumar() == nr && strstr(this->cheltuieli[i].getTip(),tip))
			this->cheltuieli[i] = c;
}

Cheltuiala* Repo::getAll() {
	return this->cheltuieli;
}

int Repo::getSize() {
	return this->n;
}
