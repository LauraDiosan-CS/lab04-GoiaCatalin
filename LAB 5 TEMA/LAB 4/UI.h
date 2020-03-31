#pragma once
#include "Service.h"
class UI {
private:
    Service service;
    void displayMenu();
    void uiAddStudent(string cmd);
    void uiShowAll();
    void uiUpdate(string cmd);
    void uiDelete(string cmd);
    void uiPropCheltuieli(string cmd);
    void uiSumaCheltuieli(string cmd);
    void uiFilterCheltuieliTip(string cmd);
    void uiFilterCheltuieliSum(string cmd);
    void undo(Cheltuiala history[], int n);
public:
    UI();
    UI(Service& service);
    void runUI();
};