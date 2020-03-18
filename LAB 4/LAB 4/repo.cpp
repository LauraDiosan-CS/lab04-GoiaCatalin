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

Cheltuiala* Repo::getAll() {
	return this->cheltuieli;
}

int Repo::getSize() {
	return this->n;
}

