
#include "CustomerSection.h"
#include "MenuManager.h"
#include "OrderManager.h"
#include "TableManager.h"
#include "Food.h"

#include <iostream>
#include <limits>

using namespace std;
CustomerSection::CustomerSection()
{
}

void CustomerSection::showMenu()
{
    int choice;

    while (true)
    {
        cout << "\n====================================" << endl;
        cout << "          CUSTOMER SECTION          " << endl;
        cout << "====================================" << endl;
        cout << "1. View Food Menu" << endl;
        cout << "2. Place Order" << endl;
        cout << "3. Back to Main Menu" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice)
        {
            case 1:
            {
                MenuManager menuManager;
                menuManager.viewFoods();
                break;
            }

            case 2:
            {
                MenuManager menuManager;
                TableManager tableManager;
                OrderManager orderManager;
                Food food;

                int foodID, quantity, customerID, tableID;

                // Step 1: Display food menu
                cout << "\n========== FOOD MENU ==========" << endl;
                menuManager.viewFoods();

                cout << "\nEnter Food ID: ";
                if (!(cin >> foodID))
                {
                    cout << "Invalid food ID!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                if (!menuManager.getFoodByID(foodID, food))
                {
                    cout << "Food not found!" << endl;
                    break;
                }

                // Step 2: Ask for quantity
                cout << "Enter Quantity: ";
                if (!(cin >> quantity) || quantity <= 0)
                {
                    cout << "Quantity must be greater than zero!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                // Step 3: Ask for customer ID
                cout << "Enter Customer ID: ";
                if (!(cin >> customerID) || customerID <= 0)
                {
                    cout << "Invalid customer ID!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                // Step 4: Show tables
                cout << "\n========== AVAILABLE TABLES ==========" << endl;
                tableManager.viewTables();

                // Step 5: Select table
                cout << "\nEnter Table ID to reserve: ";
                if (!(cin >> tableID) || tableID <= 0)
                {
                    cout << "Invalid table ID!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                if (!tableManager.isTableAvailable(tableID))
                {
                    cout << "That table is not available!" << endl;
                    break;
                }

                // Step 6: Place order and reserve table
                orderManager.placeCustomerOrder(
                    foodID, quantity, customerID, tableID
                );

                break;
            }

            case 3:
                return;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}

