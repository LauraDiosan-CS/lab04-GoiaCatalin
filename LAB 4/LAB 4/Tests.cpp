#include <assert.h>
#include <string.h>
#include "Tests.h"
#include "Cheltuiala.h"
#include "Repo.h"

void testGetteriCheltuiala() {
	char* tip = new char[10];
	strcpy_s(tip, sizeof "caldura", "caldura");
	Cheltuiala c(34, 1123, tip);
	assert(c.getNumar() == 34 );
	assert(c.getSuma() == 1123);
	assert(strcmp(c.getTip(),"caldura") == 0);
}

void testSetteriCheltuiala() {
	char* tip = new char[10];
	strcpy_s(tip, sizeof "caldura", "caldura");
	Cheltuiala c(34, 1123, tip);
	c.setNumar(55);
	c.setSuma(222);
	char tip1[4] = "apa";
	c.setTip(tip1);
	assert(c.getNumar() == 55);
	assert(c.getSuma() == 222);
	assert(strcmp(c.getTip(), "apa") == 0);
}

void testAddCheltuiala() {
	Repo rep;
	char* tip = new char[10];
	strcpy_s(tip, sizeof "caldura", "caldura");
	Cheltuiala c(23, 1123, tip);
	rep.addCheltuiala(c);
	assert(rep.getAll()[0] == c);
}

void testGetSize() {
	Repo rep;
	char* tip = new char[10];
	strcpy_s(tip, sizeof "caldura", "caldura");
	Cheltuiala c(23, 1123, tip);
	rep.addCheltuiala(c);
	assert(rep.getSize() == 1);
}
