#include "Admin.h"

Admin::Admin()
    : User("sadiq", "sadiq123")
{
}

Admin::Admin(string username, string password)
    : User(username, password)
{
}

void Admin::showAdminDashboard()
{
    int choice;

    MenuManager menuManager;
    CustomerManager customerManager;
    TableManager tableManager;
    OrderManager orderManager;
    BillingManager billingManager;
    ReportManager reportManager;
    while (true)
    {
        cout << endl;
        cout << "==================================================" << endl;
        cout << "                 ADMIN DASHBOARD                  " << endl;
        cout << "==================================================" << endl;
        cout << "1. Manage Menu" << endl;
        cout << "2. Manage Customers" << endl;
        cout << "3. Manage Tables" << endl;
        cout << "4. Manage Orders" << endl;
        cout << "5. Billing" << endl;
        cout << "6. Reports" << endl;
        cout << "7. Logout" << endl;
        cout << "==================================================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                menuManager.showMenu();
                break;
            case 2:
                customerManager.showMenu();
                break;
            case 3:
                tableManager.showMenu();
                break;

            case 4:
                orderManager.showMenu();
                break;

            case 5:
                billingManager.generateBill();
                break;
            case 6:
               reportManager.showMenu();
                break;

            case 7:
                cout << "\nLogging out..." << endl;
                return;

            default:
                cout << "\nInvalid choice. Please try again." << endl;
        }
    }
}
