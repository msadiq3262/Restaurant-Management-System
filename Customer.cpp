#include "Customer.h"

Customer::Customer()
{
    customerID = 0;
    customerName = "";
    phone = "";
    address = "";
}

Customer::Customer(int id, string name, string phone, string address)
{
    customerID = id;
    customerName = name;
    this->phone = phone;
    this->address = address;
}

void Customer::setCustomerID(int id)
{
    customerID = id;
}

void Customer::setCustomerName(string name)
{
    customerName = name;
}

void Customer::setPhone(string phone)
{
    this->phone = phone;
}

void Customer::setAddress(string address)
{
    this->address = address;
}

int Customer::getCustomerID()
{
    return customerID;
}

string Customer::getCustomerName()
{
    return customerName;
}

string Customer::getPhone()
{
    return phone;
}

string Customer::getAddress()
{
    return address;
}

void Customer::displayCustomer()
{
    cout << "---------------------------------------------" << endl;
    cout << "Customer ID   : " << customerID << endl;
    cout << "Customer Name : " << customerName << endl;
    cout << "Phone         : " << phone << endl;
    cout << "Address       : " << address << endl;
    cout << "---------------------------------------------" << endl;
}
