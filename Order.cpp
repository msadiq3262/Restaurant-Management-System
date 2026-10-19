
#include "Order.h"

Order::Order()
{
    orderID = 0;
    customerID = 0;
    foodID = 0;
    quantity = 0;
    total = 0.0;
    status = "Active";
    tableID = 0;
}

Order::Order(int orderID, int customerID, int foodID,
             int quantity, double total, string status)
{
    this->orderID = orderID;
    this->customerID = customerID;
    this->foodID = foodID;
    this->quantity = quantity;
    this->total = total;
    this->status = status;
    tableID = 0;
}

Order::Order(int orderID, int customerID, int foodID,
             int quantity, double total, string status, int tableID)
{
    this->orderID = orderID;
    this->customerID = customerID;
    this->foodID = foodID;
    this->quantity = quantity;
    this->total = total;
    this->status = status;
    this->tableID = tableID;
}

void Order::setOrderID(int id)
{
    orderID = id;
}

void Order::setCustomerID(int id)
{
    customerID = id;
}

void Order::setFoodID(int id)
{
    foodID = id;
}

void Order::setQuantity(int quantity)
{
    this->quantity = quantity;
}

void Order::setTotal(double total)
{
    this->total = total;
}

void Order::setStatus(string status)
{
    this->status = status;
}

void Order::setTableID(int id)
{
    tableID = id;
}

int Order::getOrderID()
{
    return orderID;
}

int Order::getCustomerID()
{
    return customerID;
}

int Order::getFoodID()
{
    return foodID;
}

int Order::getQuantity()
{
    return quantity;
}

double Order::getTotal()
{
    return total;
}

string Order::getStatus()
{
    return status;
}

int Order::getTableID()
{
    return tableID;
}

void Order::displayOrder()
{
    cout << "\nOrder ID    : " << orderID << endl;
    cout << "Customer ID : " << customerID << endl;
    cout << "Food ID     : " << foodID << endl;
    cout << "Quantity    : " << quantity << endl;
    cout << "Total       : Rs " << total << endl;
    cout << "Table ID    : " << tableID << endl;
    cout << "Status      : " << status << endl;
}

