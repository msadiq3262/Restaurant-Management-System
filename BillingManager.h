
#ifndef BILLING_MANAGER_H
#define BILLING_MANAGER_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Order.h"
#include "OrderManager.h"
#include "MenuManager.h"

using namespace std;

class BillingManager
{
private:
    string filename;

public:
    BillingManager();

    void generateBill();
    void generateBillForOrder(int orderID);
};

#endif

