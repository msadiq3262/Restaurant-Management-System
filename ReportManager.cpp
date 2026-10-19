
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

#include "ReportManager.h"

using namespace std;

// Stores information read from orders.txt
struct ReportOrder
{
    int orderID;
    int customerID;
    int foodID;
    int quantity;
    double total;
    string status;
    int tableID;
};

// Stores totals for each food item
struct FoodSales
{
    int foodID;
    int quantitySold;
    double revenue;
};

// Reads the seven-line order records
vector<ReportOrder> loadReportOrders()
{
    vector<ReportOrder> orders;
    ifstream file("orders.txt");

    if (!file.is_open())
    {
        cout << "\nWarning: orders.txt could not be opened.\n";
        return orders;
    }

    string lines[7];

    while (getline(file, lines[0]))
    {
        bool complete = true;

        for (int i = 1; i < 7; i++)
        {
            if (!getline(file, lines[i]))
            {
                complete = false;
                break;
            }
        }

        if (!complete)
        {
            cout << "\nWarning: Incomplete order record found.\n";
            break;
        }

        ReportOrder order;

        stringstream s1(lines[0]);
        stringstream s2(lines[1]);
        stringstream s3(lines[2]);
        stringstream s4(lines[3]);
        stringstream s5(lines[4]);
        stringstream s7(lines[6]);

        if (!(s1 >> order.orderID) ||
            !(s2 >> order.customerID) ||
            !(s3 >> order.foodID) ||
            !(s4 >> order.quantity) ||
            !(s5 >> order.total) ||
            !(s7 >> order.tableID))
        {
            cout << "\nWarning: Invalid order record skipped.\n";
            continue;
        }

        order.status = lines[5];

        // Remove carriage return if the file uses Windows line endings.
        if (!order.status.empty() &&
            order.status[order.status.length() - 1] == '\r')
        {
            order.status.erase(order.status.length() - 1);
        }

        orders.push_back(order);
    }

    file.close();
    return orders;
}

ReportManager::ReportManager()
{
}

void ReportManager::showMenu()
{
    int choice;

    while (true)
    {
        cout << "\n===== REPORT MANAGER =====\n";
        cout << "1. Sales Report\n";
        cout << "2. Food Report\n";
        cout << "0. Back to Admin Menu\n";
        cout << "Enter choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice)
        {
            case 1:
                showSalesReport();
                break;

            case 2:
                showFoodReport();
                break;

            case 0:
                cout << "Returning to Admin Menu...\n";
                return;

            default:
                cout << "Invalid choice!\n";
        }
    }
}

void ReportManager::showSalesReport()
{
    vector<ReportOrder> orders = loadReportOrders();

    int totalOrders = 0;
    int activeOrders = 0;
    int cancelledOrders = 0;
    double totalSales = 0.0;

    for (int i = 0; i < (int)orders.size(); i++)
    {
        totalOrders++;

        if (orders[i].status == "Cancelled")
        {
            cancelledOrders++;
        }
        else
        {
            activeOrders++;
            totalSales += orders[i].total;
        }
    }

    cout << "\n========== SALES REPORT ==========\n";
    cout << "Total Orders      : " << totalOrders << endl;
    cout << "Active Orders     : " << activeOrders << endl;
    cout << "Cancelled Orders  : " << cancelledOrders << endl;
    cout << fixed << setprecision(2);
    cout << "Total Sales       : Rs " << totalSales << endl;
    cout << "==================================\n";
}

void ReportManager::showFoodReport()
{
    vector<ReportOrder> orders = loadReportOrders();
    vector<FoodSales> foodSales;

    for (int i = 0; i < (int)orders.size(); i++)
    {
        // Do not count cancelled orders as sales.
        if (orders[i].status == "Cancelled")
        {
            continue;
        }

        int foodID = orders[i].foodID;
        int position = -1;

        for (int j = 0; j < (int)foodSales.size(); j++)
        {
            if (foodSales[j].foodID == foodID)
            {
                position = j;
                break;
            }
        }

        if (position == -1)
        {
            FoodSales item;
            item.foodID = foodID;
            item.quantitySold = orders[i].quantity;
            item.revenue = orders[i].total;

            foodSales.push_back(item);
        }
        else
        {
            foodSales[position].quantitySold += orders[i].quantity;
            foodSales[position].revenue += orders[i].total;
        }
    }

    cout << "\n========== FOOD SALES REPORT ==========\n";

    if (foodSales.empty())
    {
        cout << "No food sales found.\n";
        cout << "=======================================\n";
        return;
    }

    cout << left
         << setw(15) << "Food ID"
         << setw(18) << "Quantity Sold"
         << "Revenue (Rs)" << endl;

    cout << "---------------------------------------\n";

    double grandTotal = 0.0;
    int totalQuantity = 0;

    cout << fixed << setprecision(2);

    for (int i = 0; i < (int)foodSales.size(); i++)
    {
        cout << left
             << setw(15) << foodSales[i].foodID
             << setw(18) << foodSales[i].quantitySold
             << foodSales[i].revenue << endl;

        grandTotal += foodSales[i].revenue;
        totalQuantity += foodSales[i].quantitySold;
    }

    cout << "---------------------------------------\n";
    cout << "Total Quantity Sold: " << totalQuantity << endl;
    cout << "Total Food Revenue : Rs " << grandTotal << endl;
    cout << "=======================================\n";
}

