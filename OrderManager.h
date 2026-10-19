
#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Order.h"
#include "Food.h"
#include "MenuManager.h"
#include "TableManager.h"

using namespace std;

class OrderManager
{
private:
    vector<Order> orders;
    string filename;
    MenuManager menuManager;

 
public:
    OrderManager();

    void addOrder();
    void viewOrders();
    void searchOrder();
    void cancelOrder();
    void showMenu();
     void loadOrders();
    void saveOrders();


    // Existing customer-order function
    void placeCustomerOrder(int foodID, int quantity, int customerID);

    // New function that includes a table ID
    void placeCustomerOrder(int foodID, int quantity,int customerID, int tableID);
};

#endif

