
#ifndef TABLE_MANAGER_H
#define TABLE_MANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Table.h"

using namespace std;

class TableManager
{
private:
    vector<Table> tables;
    string filename;

    void loadTables();
    void saveTables();

public:
    TableManager();

    void addTable();
    void viewTables();
    void reserveTable();
    void freeTable();

    bool isTableAvailable(int tableID);
    bool reserveTableByID(int tableID);
    bool freeTableByID(int tableID);

    void showMenu();
};

#endif

