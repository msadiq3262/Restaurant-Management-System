#include "CustomerManager.h"

CustomerManager::CustomerManager()
{
    filename = "customers.txt";

    loadCustomers();
}

void CustomerManager::loadCustomers()
{
    std::ifstream file(filename.c_str());

    if (!file)
    {
        return;
    }

    int id;
    string name;
    string phone;
    string address;

    while (file >> id)
    {
        file.ignore();

        getline(file, name);
        getline(file, phone);
        getline(file, address);

        Customer customer(id, name, phone, address);

        customers.push_back(customer);
    }

    file.close();
}

void CustomerManager::saveCustomers()
{
    std::ofstream file(filename.c_str());

    if (!file)
    {
        cout << "Error: Could not open customer file!" << endl;
        return;
    }

    for (int i = 0; i < customers.size(); i++)
    {
        file << customers[i].getCustomerID() << endl;
        file << customers[i].getCustomerName() << endl;
        file << customers[i].getPhone() << endl;
        file << customers[i].getAddress() << endl;
    }

    file.close();
}

void CustomerManager::addCustomer()
{
    int id;
    string name;
    string phone;
    string address;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "                ADD CUSTOMER                      " << endl;
    cout << "==================================================" << endl;

    cout << "Enter Customer ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Customer Name: ";
    getline(cin, name);

    cout << "Enter Phone: ";
    getline(cin, phone);

    cout << "Enter Address: ";
    getline(cin, address);

    Customer customer(id, name, phone, address);

    customers.push_back(customer);

    saveCustomers();

    cout << endl;
    cout << "Customer added successfully!" << endl;
}

void CustomerManager::viewCustomers()
{
    cout << endl;
    cout << "==================================================" << endl;
    cout << "                 CUSTOMERS                        " << endl;
    cout << "==================================================" << endl;

    if (customers.empty())
    {
        cout << "No customers found." << endl;
        return;
    }

    for (int i = 0; i < customers.size(); i++)
    {
        customers[i].displayCustomer();
    }
}

void CustomerManager::searchCustomer()
{
    int id;
    bool found = false;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "                SEARCH CUSTOMER                   " << endl;
    cout << "==================================================" << endl;

    cout << "Enter Customer ID: ";
    cin >> id;

    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].getCustomerID() == id)
        {
            cout << endl;
            cout << "Customer found!" << endl;

            customers[i].displayCustomer();

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << endl;
        cout << "Customer not found!" << endl;
    }
}

void CustomerManager::updateCustomer()
{
    int id;
    bool found = false;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "                UPDATE CUSTOMER                   " << endl;
    cout << "==================================================" << endl;

    cout << "Enter Customer ID to update: ";
    cin >> id;

    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].getCustomerID() == id)
        {
            string name;
            string phone;
            string address;

            cin.ignore();

            cout << "Enter new Customer Name: ";
            getline(cin, name);

            cout << "Enter new Phone: ";
            getline(cin, phone);

            cout << "Enter new Address: ";
            getline(cin, address);

            customers[i].setCustomerName(name);
            customers[i].setPhone(phone);
            customers[i].setAddress(address);

            saveCustomers();

            cout << endl;
            cout << "Customer updated successfully!" << endl;

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << endl;
        cout << "Customer not found!" << endl;
    }
}

void CustomerManager::deleteCustomer()
{
    int id;
    bool found = false;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "                DELETE CUSTOMER                   " << endl;
    cout << "==================================================" << endl;

    cout << "Enter Customer ID to delete: ";
    cin >> id;

    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].getCustomerID() == id)
        {
            customers.erase(customers.begin() + i);

            saveCustomers();

            cout << endl;
            cout << "Customer deleted successfully!" << endl;

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << endl;
        cout << "Customer not found!" << endl;
    }
}

void CustomerManager::showMenu()
{
    int choice;

    while (true)
    {
        cout << endl;
        cout << "==================================================" << endl;
        cout << "              CUSTOMER MANAGEMENT                 " << endl;
        cout << "==================================================" << endl;
        cout << "1. Add Customer" << endl;
        cout << "2. View Customers" << endl;
        cout << "3. Search Customer" << endl;
        cout << "4. Update Customer" << endl;
        cout << "5. Delete Customer" << endl;
        cout << "6. Back" << endl;
        cout << "==================================================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addCustomer();
                break;

            case 2:
                viewCustomers();
                break;

            case 3:
                searchCustomer();
                break;

            case 4:
                updateCustomer();
                break;

            case 5:
                deleteCustomer();
                break;

            case 6:
                return;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
