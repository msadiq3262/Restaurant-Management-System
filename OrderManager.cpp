#include "OrderManager.h"
#include "TableManager.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

OrderManager::OrderManager()
{
    filename = "orders.txt";
    loadOrders();
}


void OrderManager::loadOrders()
{
    orders.clear();

    ifstream file(filename.c_str());

    if (!file.is_open())
    {
        cout << "orders.txt could not be opened." << endl;
        return;
    }

    string line;
    int recordNumber = 0;

    while (true)
    {
        int orderID;
        int customerID;
        int foodID;
        int quantity;
        int tableID;

        double total;
        string status;

        // Read Order ID
        if (!getline(file, line))
            break;

        recordNumber++;

        stringstream s1(line);

        if (!(s1 >> orderID))
        {
            cout << "Invalid Order ID in record "
                 << recordNumber << endl;
            break;
        }

        // Read Customer ID
        if (!getline(file, line))
            break;

        stringstream s2(line);

        if (!(s2 >> customerID))
            break;

        // Read Food ID
        if (!getline(file, line))
            break;

        stringstream s3(line);

        if (!(s3 >> foodID))
            break;

        // Read Quantity
        if (!getline(file, line))
            break;

        stringstream s4(line);

        if (!(s4 >> quantity))
            break;

        // Read Total
        if (!getline(file, line))
            break;

        stringstream s5(line);

        if (!(s5 >> total))
            break;

        // Read Status
        if (!getline(file, status))
            break;

        // Read Table ID
        if (!getline(file, line))
            break;

        stringstream s6(line);

        if (!(s6 >> tableID))
            tableID = 0;

        cout << "Reading order ID: " << orderID << endl;

        Order order(
            orderID,
            customerID,
            foodID,
            quantity,
            total,
            status,
            tableID
        );

        orders.push_back(order);

        cout << "Order loaded successfully." << endl;
    }

    file.close();

    cout << "Finished loading orders." << endl;
}


void OrderManager::saveOrders()
{
    ofstream file(filename.c_str());

    if (!file.is_open())
    {
        cout << "Error: Could not save orders.txt!" << endl;
        return;
    }

    for (size_t i = 0; i < orders.size(); i++)
    {
        file << orders[i].getOrderID() << '\n';
        file << orders[i].getCustomerID() << '\n';
        file << orders[i].getFoodID() << '\n';
        file << orders[i].getQuantity() << '\n';
        file << orders[i].getTotal() << '\n';
        file << orders[i].getStatus() << '\n';
        file << orders[i].getTableID() << '\n';
    }

    if (!file)
    {
        cout << "Error: A problem occurred while writing orders.txt!" << endl;
    }

    file.close();
}

void OrderManager::addOrder()
{
    int orderID, customerID, foodID, quantity;
    double total;
    string status;

    loadOrders();

    cout << "\nEnter Order ID: ";
    if (!(cin >> orderID))
    {
        cout << "Invalid input!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (size_t i = 0; i < orders.size(); i++)
    {
        if (orders[i].getOrderID() == orderID)
        {
            cout << "That Order ID already exists!" << endl;
            return;
        }
    }

    cout << "Enter Customer ID: ";
    if (!(cin >> customerID))
    {
        cout << "Invalid input!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    menuManager.viewFoods();

    cout << "Enter Food ID: ";
    if (!(cin >> foodID))
    {
        cout << "Invalid input!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    Food food;
    if (!menuManager.getFoodByID(foodID, food))
    {
        cout << "Food not found!" << endl;
        return;
    }

    cout << "Enter Quantity: ";
    if (!(cin >> quantity) || quantity <= 0)
    {
        cout << "Invalid quantity!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    total = food.getPrice() * quantity;
    status = "Active";

    Order order(orderID, customerID, foodID, quantity,
                total, status, 0);

    orders.push_back(order);
    saveOrders();

    cout << "Order added successfully!" << endl;
}

void OrderManager::viewOrders()
{
    cout << "\nTEST 1: Entered viewOrders()" << endl;

    cout << "TEST 2: About to call loadOrders()" << endl;

    loadOrders();

    cout << "TEST 3: loadOrders() completed" << endl;

    cout << "Number of orders: " << orders.size() << endl;

    if (orders.empty())
    {
        cout << "No orders found." << endl;
        return;
    }

    cout << "TEST 4: About to display the first order" << endl;

    orders[0].displayOrder();

    cout << "TEST 5: First order displayed" << endl;
}



void OrderManager::searchOrder()
{
    loadOrders();

    int id;

    cout << "\nEnter Order ID to search: ";
    if (!(cin >> id))
    {
        cout << "Invalid input!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (size_t i = 0; i < orders.size(); i++)
    {
        if (orders[i].getOrderID() == id)
        {
            orders[i].displayOrder();
            return;
        }
    }

    cout << "Order not found!" << endl;
}

void OrderManager::cancelOrder()
{
    loadOrders();

    if (orders.empty())
    {
        cout << "\nNo orders available to cancel." << endl;
        return;
    }

    int id;

    cout << "\nEnter Order ID to cancel: ";
    if (!(cin >> id))
    {
        cout << "Invalid input!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (size_t i = 0; i < orders.size(); i++)
    {
        if (orders[i].getOrderID() == id)
        {
            if (orders[i].getStatus() == "Cancelled")
            {
                cout << "This order is already cancelled!" << endl;
                return;
            }

            int tableID = orders[i].getTableID();

            orders[i].setStatus("Cancelled");
            saveOrders();

            if (tableID > 0)
            {
                TableManager tableManager;
                tableManager.freeTableByID(tableID);
            }

            cout << "Order cancelled successfully!" << endl;
            return;
        }
    }

    cout << "Order not found!" << endl;
}


void OrderManager::showMenu()
{
    int choice;

    while (true)
    {
        cout << "\n========== ORDER MANAGEMENT ==========" << endl;
        cout << "1. Add Order" << endl;
        cout << "2. View Orders" << endl;
        cout << "3. Search Order" << endl;
        cout << "4. Cancel Order" << endl;
        cout << "5. Back" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input! Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice)
        {
            case 1:
                addOrder();
                break;

            case 2:
                viewOrders();
                cout << "\nPress Enter to continue...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                break;

            case 3:
                searchOrder();
                break;

            case 4:
                cancelOrder();
                break;

            case 5:
                cout << "Returning to previous menu..." << endl;
                return;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
}


void OrderManager::placeCustomerOrder(int foodID, int quantity,
                                      int customerID)
{
    placeCustomerOrder(foodID, quantity, customerID, 0);
}

void OrderManager::placeCustomerOrder(int foodID, int quantity,
                                      int customerID, int tableID)
{
    loadOrders();

    if (quantity <= 0)
    {
        cout << "Quantity must be greater than zero!" << endl;
        return;
    }

    Food food;
    if (!menuManager.getFoodByID(foodID, food))
    {
        cout << "Food not found!" << endl;
        return;
    }

    if (tableID > 0)
    {
        TableManager tableManager;

        if (!tableManager.isTableAvailable(tableID))
        {
            cout << "Selected table is not available!" << endl;
            return;
        }

        if (!tableManager.reserveTableByID(tableID))
        {
            cout << "Could not reserve the table. Order was not added." << endl;
            return;
        }
    }

    int newOrderID = 1;
    for (size_t i = 0; i < orders.size(); i++)
    {
        if (orders[i].getOrderID() >= newOrderID)
        {
            newOrderID = orders[i].getOrderID() + 1;
        }
    }

    double total = food.getPrice() * quantity;

    Order order(newOrderID, customerID, foodID, quantity,
                total, "Active", tableID);

    orders.push_back(order);
    saveOrders();

    cout << "\n========== ORDER RECEIPT ==========" << endl;
    cout << "Order ID    : " << newOrderID << endl;
    cout << "Customer ID : " << customerID << endl;
    cout << "Food ID     : " << foodID << endl;
    cout << "Quantity    : " << quantity << endl;
    cout << "Total       : Rs " << total << endl;

    if (tableID > 0)
    {
        cout << "Table ID    : " << tableID << endl;
    }
    else
    {
        cout << "Table ID    : Not selected" << endl;
    }

    cout << "Status      : Active" << endl;
    cout << "===================================" << endl;
}

