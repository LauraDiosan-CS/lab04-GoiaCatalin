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

void Service::addCheltuialaS(int nr, int suma, char* tip) {
	Cheltuiala c(nr, suma, tip);
	this->rep.addCheltuiala(c);
}

void Service::deleteCheltuialaS(int nr) {
	this->rep.deleteCheltuiala(nr);
}

void Service::updateCheltuialaS(int nr, int new_nr, int new_suma, char* new_tip) {
	Cheltuiala c(new_nr, new_suma, new_tip);
	this->rep.updateCheltuiala(nr, c);
}

Cheltuiala* Service::getAll() {
	return this->rep.getAll();
}

int Service::getSize() {
	return this->rep.getSize();
}


