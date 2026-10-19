
#include "TableManager.h"
#include <limits>

TableManager::TableManager()
{
    filename = "tables.txt";
    loadTables();
}

void TableManager::loadTables()
{
    tables.clear();

    ifstream file(filename.c_str());

    if (!file.is_open())
    {
        return;
    }

    int id, seats;
    string status;

    while (file >> id)
    {
        if (!(file >> seats))
        {
            break;
        }

        file.ignore(numeric_limits<streamsize>::max(), '\n');

        if (!getline(file, status))
        {
            break;
        }

        Table table(id, seats, status);
        tables.push_back(table);
    }

    file.close();
}

void TableManager::saveTables()
{
    ofstream file(filename.c_str());

    if (!file.is_open())
    {
        cout << "Error: Cannot save tables.txt!" << endl;
        return;
    }

    for (int i = 0; i < (int)tables.size(); i++)
    {
        file << tables[i].getTableID() << endl;
        file << tables[i].getSeats() << endl;
        file << tables[i].getStatus() << endl;
    }

    file.close();
}

void TableManager::addTable()
{
    int id, seats;

    cout << "\nEnter Table ID: ";
    if (!(cin >> id) || id <= 0)
    {
        cout << "Invalid Table ID!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (int i = 0; i < (int)tables.size(); i++)
    {
        if (tables[i].getTableID() == id)
        {
            cout << "This Table ID already exists!" << endl;
            return;
        }
    }

    cout << "Enter Number of Seats: ";
    if (!(cin >> seats) || seats <= 0)
    {
        cout << "Invalid number of seats!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    Table table(id, seats, "Available");
    tables.push_back(table);

    saveTables();

    cout << "Table added successfully!" << endl;
}

void TableManager::viewTables()
{
    loadTables();

    if (tables.empty())
    {
        cout << "\nNo tables found. Add a table first." << endl;
        return;
    }

    cout << "\n========== TABLE LIST ==========" << endl;

    for (int i = 0; i < (int)tables.size(); i++)
    {
        tables[i].displayTable();
        cout << "-------------------------------" << endl;
    }
}

bool TableManager::isTableAvailable(int tableID)
{
    loadTables();

    for (int i = 0; i < (int)tables.size(); i++)
    {
        if (tables[i].getTableID() == tableID)
        {
            return tables[i].getStatus() == "Available";
        }
    }

    return false;
}

bool TableManager::reserveTableByID(int tableID)
{
    loadTables();

    for (int i = 0; i < (int)tables.size(); i++)
    {
        if (tables[i].getTableID() == tableID)
        {
            if (tables[i].getStatus() != "Available")
            {
                cout << "This table is not available!" << endl;
                return false;
            }

            tables[i].setStatus("Reserved");
            saveTables();

            cout << "Table reserved successfully!" << endl;
            return true;
        }
    }

    cout << "Table not found!" << endl;
    return false;
}

void TableManager::reserveTable()
{
    int id;

    viewTables();

    cout << "\nEnter Table ID to reserve: ";

    if (!(cin >> id))
    {
        cout << "Invalid input!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    reserveTableByID(id);
}

void TableManager::freeTable()
{
    loadTables();

    int id;

    viewTables();

    cout << "\nEnter Table ID to make available: ";

    if (!(cin >> id))
    {
        cout << "Invalid input!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (int i = 0; i < (int)tables.size(); i++)
    {
        if (tables[i].getTableID() == id)
        {
            tables[i].setStatus("Available");
            saveTables();

            cout << "Table is now available!" << endl;
            return;
        }
    }

    cout << "Table not found!" << endl;
}

void TableManager::showMenu()
{
    int choice;

    while (true)
    {
        cout << "\n========== TABLE MANAGEMENT ==========" << endl;
        cout << "1. Add Table" << endl;
        cout << "2. View Tables" << endl;
        cout << "3. Reserve Table" << endl;
        cout << "4. Free Table" << endl;
        cout << "5. Back" << endl;
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
                addTable();
                break;

            case 2:
                viewTables();
                break;

            case 3:
                reserveTable();
                break;

            case 4:
                freeTable();
                break;

            case 5:
                return;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
bool TableManager::freeTableByID(int tableID)
{
    loadTables();

    for (int i = 0; i < (int)tables.size(); i++)
    {
        if (tables[i].getTableID() == tableID)
        {
            tables[i].setStatus("Available");
            saveTables();

            cout << "Table " << tableID
                 << " is now available!" << endl;

            return true;
        }
    }

    cout << "Table not found!" << endl;
    return false;
}


