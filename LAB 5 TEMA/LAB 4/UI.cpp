#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include "UI.h"
#include "Service.h"

using namespace std;

UI::UI()
{
}

UI::UI(Service& service)
{
	this->service = service;
}

void UI::displayMenu()
{
	cout << "\n";
	cout << "1. Scrie \"add {numar} {suma} {tip} \" pentru a adauga o cheltuiala\n";
	cout << "2. Scrie \"show\" pentru a afisa toate cheltuielile\n";
	cout << "3. Scrie \"update {numar vechi} {tip vechi} {numar nou} {suma noua} {tip nou}\" pentru a updata cheltuiala cu numarul ales\n";
	cout << "4. Scrie \"delete {numar} {suma} {tip}\" pentru a sterge cheltuielile apartamentului ales\n";
	cout << "5. Scrie \"prop {numar}\" pentru a afisa cheltuielile apartamenutlui cu numarul ales\n";
	cout << "6. Scrie \"suma {tip}\" pentru a insuma cheltuielile care apartin unui tip\n";
	cout << "7. Scrie \"filter_sum {suma}\" pentru a filtra cheltuielile sub o anumita suma\n";
	cout << "8. Scrie \"filter_tip {tip}\" pentru a filtra cheltuielile cu acelasi tip\n";
	cout << "x. Scrie \"exit\" pentru a inchide aplicatia\n";
	cout << "\nGive option: \n";
}

void UI::uiAddStudent(string cmd)
{
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	
	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int nr = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int suma= stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* tip = new char[token.length() + 1];
	strcpy_s(tip, token.length() + 1, token.c_str());


	this->service.addCheltuiala(nr, suma, tip);
}

void UI::uiShowAll()
{      
	for (int i = 0; i < service.getSize(); i++)
	{
		cout << service.getAll()[i] << " ";
		cout << endl;
	}

	cout << endl;
}

void UI::uiUpdate(string cmd)
{
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	
	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int old_nr = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* old_tip = new char[token.length() + 1];
	strcpy_s(old_tip, token.length() + 1, token.c_str());

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int new_nr = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int new_suma = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* new_tip = new char[token.length() + 1];
	strcpy_s(new_tip, token.length() + 1, token.c_str());


	this->service.updateCheltuiala(old_nr,old_tip, new_nr, new_suma, new_tip);
}

void UI::uiDelete(string cmd)
{
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int nr = stoi(token);

	this->service.deleteCheltuiala(nr);
}


void UI::uiPropCheltuieli(string cmd)
{

	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int nr = stoi(token);

	int resultLen = 0;
	Cheltuiala result[10];
	int n = service.getSize();
	Cheltuiala* cheltuieli = service.getAll();
	service.propCheltuieli(cheltuieli, n, nr, result, resultLen);
	cout << endl << "Cheltuielile sunt: " << endl;
	for (int i = 0; i < resultLen; i++) {
		cout << result[i] << " ";
		cout << endl;
	}
	cout << endl;
}

void UI::uiSumaCheltuieli(string cmd)
{
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* tip = new char[token.length() + 1];
	strcpy_s(tip, token.length() + 1, token.c_str());

	int length = 0;
	int n = service.getSize();
	Cheltuiala* cheltuieli = service.getAll();
	int suma = service.sumaCheltuieli(cheltuieli, n, tip);
	cout<<"Suma cheltuielilor apartamentelor la " << tip <<" : "<< suma<<endl;

}


void UI::uiFilterCheltuieliSum(string cmd)
{
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int suma = stoi(token);

	int resultLen = 0;
	Cheltuiala result[10];
	int n = service.getSize();
	char* tip = new char[10];
	strcpy_s(tip, sizeof "x", "x");
	Cheltuiala* cheltuieli = service.getAll();
	service.filterCheltuieli(cheltuieli, n, suma, tip ,result, resultLen);
	cout << endl << "Cheltuielile sunt: " << endl;
	for (int i = 0; i < resultLen; i++) {
		cout << result[i] << " ";
		cout << endl;
	}

}
void UI::uiFilterCheltuieliTip(string cmd)
{
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* tip = new char[token.length() + 1];
	strcpy_s(tip, token.length() + 1, token.c_str());

	int resultLen = 0;
	Cheltuiala result[10];
	int n = service.getSize();
	Cheltuiala* cheltuieli = service.getAll();
	service.filterCheltuieli(cheltuieli, n,0, tip , result, resultLen);
	cout << endl << "Cheltuielile sunt: " << endl;
	for (int i = 0; i < resultLen; i++) {
		cout << result[i] << " ";
		cout << endl;
	}

}

void UI::undo(Cheltuiala history[], int n)
{
	service.undo(history, n);
}


void UI::runUI()
{
	bool shouldRun = true;
	string cmd;
	Cheltuiala* history = service.getAll();
	int n = service.getSize();
	while (shouldRun)
	{
		
		this->displayMenu();
		getline(cin, cmd);
		if (cmd.find("add") != string::npos)
		{	
			history = service.getAll();
			n = service.getSize();
			this->uiAddStudent(cmd);
 		}
		if (cmd.find("show") != string::npos)
		{
			this->uiShowAll();
		}
		if (cmd.find("update") != string::npos)
		{
			history = service.getAll();
			n = service.getSize();
			this->uiUpdate(cmd);
		}
		if (cmd.find("delete") != string::npos)
		{
			history = service.getAll();
			n = service.getSize();
			this->uiDelete(cmd);
		}
		if (cmd.find("prop") != string::npos)
		{
			this->uiPropCheltuieli(cmd);
		}
		if (cmd.find("suma") != string::npos)
		{
			this->uiSumaCheltuieli(cmd);
		}
		if (cmd.find("filter_sum") != string::npos)
		{
			this->uiFilterCheltuieliSum(cmd);
		}
		if (cmd.find("filter_tip") != string::npos)
		{
			this->uiFilterCheltuieliTip(cmd);
		}
		if (cmd.find("delall") != string::npos)
		{
			service.delAll();
		}
		if (cmd.find("undo") != string::npos)
		{
			this->undo(history, n);
		}
		if (cmd.find("exit") != string::npos)
		{
			shouldRun = false;
		}
	}
}
