#include "Restaurant.h"
#include "CustomerSection.h"
#include "Admin.h"

Restaurant::Restaurant()
{
    restaurantName = "My Restaurant";
}

void Restaurant::showWelcome()
{
    cout << endl;
    cout << "==================================================" << endl;
    cout << "          RESTAURANT MANAGEMENT SYSTEM            " << endl;
    cout << "==================================================" << endl;
    cout << "              " << restaurantName << endl;
    cout << "==================================================" << endl;
}

void Restaurant::showMainMenu()
{
    cout << endl;
    cout << "================ MAIN MENU =======================" << endl;
    cout << "1. Admin Login" << endl;
    cout << "2. Customer" << endl;
    cout << "3. Exit" << endl;
    cout << "==================================================" << endl;
}

void Restaurant::startSystem()
{
    int choice;

    Admin admin;

    while (true)
    {
        showMainMenu();

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                string username;
                string password;

                cout << endl;
                cout << "==================================================" << endl;
                cout << "                  ADMIN LOGIN                     " << endl;
                cout << "==================================================" << endl;

                cout << "Username: ";
                cin >> username;

                cout << "Password: ";
                cin >> password;

                if (admin.login(username, password))
                {
                    cout << endl;
                    cout << "Login successful!" << endl;

                    admin.showAdminDashboard();
                }
                else
                {
                    cout << endl;
                    cout << "Invalid username or password!" << endl;
                }

                break;
            }

        case 2:
         {
           CustomerSection customerSection;
           customerSection.showMenu();
           break;
          }

            case 3:
                cout << "\nThank you for using the Restaurant Management System!"
                     << endl;
                return;

            default:
                cout << "\nInvalid choice. Please try again." << endl;
        }
    }
}
