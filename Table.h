#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>

using namespace std;

class Table
{
private:
    int tableID;
    int seats;
    string status;

public:
    Table();
    Table(int id, int seats, string status);

    void setTableID(int id);
    void setSeats(int seats);
    void setStatus(string status);

    int getTableID();
    int getSeats();
    string getStatus();

    void displayTable();
};

#endif
