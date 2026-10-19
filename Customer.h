#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

using namespace std;

class Customer
{
private:
    int customerID;
    string customerName;
    string phone;
    string address;

public:
    Customer();
    Customer(int id, string name, string phone, string address);

    void setCustomerID(int id);
    void setCustomerName(string name);
    void setPhone(string phone);
    void setAddress(string address);

    int getCustomerID();
    string getCustomerName();
    string getPhone();
    string getAddress();

    void displayCustomer();
};

#endif
