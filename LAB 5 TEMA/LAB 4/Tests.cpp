#include <assert.h>
#include <string.h>
#include "Tests.h"
#include "Cheltuiala.h"
#include "Repo.h"
#include "Service.h"
#include <iostream>
#include "UI.h"

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
	char tip1[4] = "apa";

	c.setNumar(55);
	c.setSuma(222);
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
	rep.updateCheltuiala(23,tip1, c2);
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
	Cheltuiala c(13, 1222, tip);

	ser.addCheltuiala(13, 1222, tip);
	assert(ser.getAll()[0] == c);
}
	
void testDeleteCheltuialaS()
{
	Service ser;
	char* tip = new char[10];
	strcpy_s(tip, sizeof "caldura", "caldura");
	
	ser.addCheltuiala(13, 1222, tip);
	ser.deleteCheltuiala(13);
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
	
	ser.addCheltuiala(13, 1222, tip);
	ser.updateCheltuiala(13, tip, 14, 1211, tip1);
	assert(ser.getAll()[0] == c);
}

void testUiPropCheltuieli()
{
	Service ser;
	char* tip1 = new char[10];
	char* tip2 = new char[10];
	char* tip3 = new char[10];
	strcpy_s(tip1, sizeof "caldura", "caldura");
	strcpy_s(tip2, sizeof "apa", "apa");
	strcpy_s(tip3, sizeof "gaz", "gaz");
	Cheltuiala c1(13, 121, tip1);
	Cheltuiala c3(13, 412, tip3);
	int resultLen = 0;
	Cheltuiala result[10];

	ser.addCheltuiala(13, 121, tip1);
	ser.addCheltuiala(14, 312, tip2);
	ser.addCheltuiala(13, 412, tip3);
	int n = ser.getSize();
	Cheltuiala* cheltuieli = ser.getAll();
	ser.propCheltuieli(cheltuieli, n, 13, result, resultLen);
	assert(result[0] == c1);
	assert(result[1] == c3);
}

void testUiSumaCheltuieli()
{
	Service ser;
	char* tip1 = new char[10];
	char* tip2 = new char[10];
	char* tip3 = new char[10];
	strcpy_s(tip1, sizeof "caldura", "caldura");
	strcpy_s(tip2, sizeof "gaz", "gaz");
	strcpy_s(tip3, sizeof "gaz", "gaz");
	
	ser.addCheltuiala(13, 121, tip1);
	ser.addCheltuiala(14, 312, tip2);
	ser.addCheltuiala(25, 412, tip3);
	int n = ser.getSize();
	Cheltuiala* cheltuieli = ser.getAll();	
	assert(ser.sumaCheltuieli(cheltuieli, n, tip3) == 724);
}

void testUiFilterCheltuieli()
{
	Service ser;
	char* tip1 = new char[10];
	char* tip2 = new char[10];
	char* tip3 = new char[10];
	char* tip = new char[10];
	strcpy_s(tip, sizeof "x", "x");
	strcpy_s(tip1, sizeof "caldura", "caldura");
	strcpy_s(tip2, sizeof "gaz", "gaz");
	strcpy_s(tip3, sizeof "gaz", "gaz");
	ser.addCheltuiala(13, 121, tip1);
	ser.addCheltuiala(14, 312, tip2);
	ser.addCheltuiala(25, 412, tip3);
	int resultLen = 0;
	Cheltuiala result[10];

	Cheltuiala c1(13, 121, tip1);
	int n = ser.getSize();
	Cheltuiala* cheltuieli = ser.getAll();
	ser.filterCheltuieli(cheltuieli, n, 200, tip ,result, resultLen);
	assert(resultLen == 1);
	assert(result[0] == c1);

}

void tests()
{
	testGetteriCheltuiala();
	testSetteriCheltuiala();
	testAddCheltuiala();
	testDeleteCheltuiala();
	testGetSize();
	testUpdateCheltuiala();
	testAddCheltuialaS();
	testDeleteCheltuialaS();
	testUpdateCheltuialaS();
	testUiPropCheltuieli();
	testUiSumaCheltuieli();
	testUiFilterCheltuieli();

}