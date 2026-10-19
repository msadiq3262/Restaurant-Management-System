
#ifndef CUSTOMERSECTION_H
#define CUSTOMERSECTION_H

#include "MenuManager.h"
#include "OrderManager.h"
#include "TableManager.h"

class CustomerSection
{
private:
    MenuManager menuManager;
    OrderManager orderManager;
    TableManager tableManager;

public:
    CustomerSection();

    void showMenu();
    void viewFoodMenu();
    void placeOrder();
};

#endif

