#include <iostream>
#include "Cheltuiala.h"
#include "UI.h"
#include "Service.h"
#include "Repo.h"
#include "Tests.h"

using namespace std;

int main()
{
    tests();
    
    Service service;
    UI ui;
    ui.runUI();
}