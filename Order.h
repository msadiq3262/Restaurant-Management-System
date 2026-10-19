
#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>

using namespace std;

class Order
{
private:
    int orderID;
    int customerID;
    int foodID;
    int quantity;
    double total;
    string status;
    int tableID;

public:
    // Default constructor
    Order();

    // Existing constructor for orders without a table ID
    Order(int orderID,
          int customerID,
          int foodID,
          int quantity,
          double total,
          string status);

    // New constructor for orders with a table ID
    Order(int orderID,
          int customerID,
          int foodID,
          int quantity,
          double total,
          string status,
          int tableID);

    // Setter functions
    void setOrderID(int id);
    void setCustomerID(int id);
    void setFoodID(int id);
    void setQuantity(int quantity);
    void setTotal(double total);
    void setStatus(string status);
    void setTableID(int id);

    // Getter functions
    int getOrderID();
    int getCustomerID();
    int getFoodID();
    int getQuantity();
    double getTotal();
    string getStatus();
    int getTableID();

    // Display order information
    void displayOrder();
};

#endif

