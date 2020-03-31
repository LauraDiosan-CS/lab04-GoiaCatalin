#pragma once
#include <ostream>
using namespace std;

class Cheltuiala {
private:
	int nr;
	int suma;
	char* tip;
public:
	Cheltuiala();
	Cheltuiala(int nr, int suma, char* tip);
	Cheltuiala(const Cheltuiala& c);
	~Cheltuiala();
	int getNumar();
	int getSuma();
	char* getTip();
	void setNumar(int nr);
	void setSuma(int varsta);
	void setTip(char* tip);
	Cheltuiala& operator=(const Cheltuiala& c);
	bool operator==(const Cheltuiala& c);
	friend ostream& operator<<(ostream& oc, const Cheltuiala& c);
};
