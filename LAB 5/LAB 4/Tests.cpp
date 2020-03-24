#include <assert.h>
#include <string.h>
#include "Tests.h"
#include "Cheltuiala.h"
#include "Repo.h"
#include "Service.h"
#include <iostream>
using namespace std;

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

///teste Repo

void testAddCheltuiala() {
	Repo rep;
	char* tip = new char[10];
	strcpy_s(tip, sizeof "caldura", "caldura");
	Cheltuiala c(23, 1123, tip);
	rep.addCheltuiala(c);
	assert(rep.getAll()[0] == c);
}

void testDeleteCheltuiala() {
	Repo rep;
	char* tip = new char[10];
	strcpy_s(tip, sizeof "caldura", "caldura");
	Cheltuiala c(23, 1123, tip);
	rep.addCheltuiala(c);
	assert(rep.getAll()[0] == c);
	rep.deleteCheltuiala(23);
	assert(rep.getSize()== 0);
}

void testUpdateCheltuiala() {
	Repo rep;
	char* tip1 = new char[10];
	char* tip2 = new char[10];
	strcpy_s(tip1, sizeof "caldura", "caldura");
	strcpy_s(tip2, sizeof "apa", "apa");
	Cheltuiala c1(23, 1123, tip1);
	Cheltuiala c2(24, 4312, tip2);
	rep.addCheltuiala(c1);
	assert(rep.getAll()[0] == c1);
	rep.updateCheltuiala(23,c2);
	assert(rep.getAll()[0] == c2);
}

void testGetSize() {
	Repo rep;
	char* tip = new char[10];
	strcpy_s(tip, sizeof "caldura", "caldura");
	Cheltuiala c(23, 1123, tip);
	rep.addCheltuiala(c);
	assert(rep.getSize() == 1);
}

///teste Service

void testAddCheltuialaS()
{
	Service ser;
	char* tip = new char[10];
	strcpy_s(tip, sizeof "caldura", "caldura");
	ser.addCheltuialaS(13, 1222, tip);
	Cheltuiala c(13, 1222, tip);
	assert(ser.getAll()[0] == c);
}
	
void testDeleteCheltuialaS()
{
	Service ser;
	char* tip = new char[10];
	strcpy_s(tip, sizeof "caldura", "caldura");
	ser.addCheltuialaS(13, 1222, tip);
	ser.deleteCheltuialaS(13);
	assert(ser.getSize() == 0);
}

void testUpdateCheltuialaS()
{
	Service ser;
	char* tip = new char[10];
	char* tip1 = new char[10];
	strcpy_s(tip1, sizeof "apa", "apa");
	strcpy_s(tip, sizeof "caldura", "caldura");
	Cheltuiala c(14, 1211, tip1);
	ser.addCheltuialaS(13, 1222, tip);
	ser.updateCheltuialaS(13, 14, 1211, tip1);
	assert(ser.getAll()[0] == c);
}
