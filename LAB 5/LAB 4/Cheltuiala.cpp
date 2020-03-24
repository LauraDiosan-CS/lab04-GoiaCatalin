#include "Cheltuiala.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>

using namespace std;

Cheltuiala::Cheltuiala() {
	this->nr = 0;
	this->suma = 0;
	this->tip = NULL;
}

Cheltuiala::Cheltuiala(int nr, int suma, char* tip)
{
	this->nr = nr;
	this->suma = suma;
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, 1 + strlen(tip), tip);
}

Cheltuiala::Cheltuiala(const Cheltuiala& c) {
	this->nr = c.nr;
	this->suma = c.suma;
	this->tip = new char[strlen(c.tip) + 1];
	strcpy_s(this->tip, 1 + strlen(c.tip), c.tip);
}

Cheltuiala::~Cheltuiala() {
	if (this->tip) {
		delete[] this->tip;
		this->tip = NULL;
	}
}

int Cheltuiala::getNumar() {
	return this->nr;
}

int Cheltuiala::getSuma() {
	return this->suma;
}

char* Cheltuiala::getTip() {
	return this->tip;
}

void Cheltuiala::setNumar(int nr) {
	this->nr = nr;
}

void Cheltuiala::setSuma(int suma) {
	this->suma = suma;
}

void Cheltuiala::setTip(char* tip)
{
	if (this->tip) {
		delete[] this->tip;
	}
	this->tip = new char[strlen(tip) + 1];
	// LA FIECARE strcpy_s, AM INLOCUIT sizeof(s) CU strlen(s) + 1
	strcpy_s(this->tip, strlen(tip) + 1, tip);
}

Cheltuiala& Cheltuiala::operator=(const Cheltuiala& c) {
	this->setNumar(c.nr);
	this->setSuma(c.suma);
	this->setTip(c.tip);
	return *this;
}

bool Cheltuiala:: operator==(const Cheltuiala& c) {
	return strcmp(this->tip, c.tip) == 0 && this->suma == c.suma && this->nr == c.nr;
}

ostream& operator<<(ostream& oc, const Cheltuiala& c)
{
	oc << c.nr << " " << c.suma << " " << c.tip;
	return oc;
}
