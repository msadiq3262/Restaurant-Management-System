#ifndef CUSTOMER_MANAGER_H
#define CUSTOMER_MANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Customer.h"

using namespace std;

class CustomerManager
{
private:
    vector<Customer> customers;
    string filename;

    void loadCustomers();
    void saveCustomers();

public:
    CustomerManager();

    void addCustomer();
    void viewCustomers();
    void searchCustomer();
    void updateCustomer();
    void deleteCustomer();

    void showMenu();
};

#endif
