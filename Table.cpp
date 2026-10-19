#include "Table.h"

Table::Table()
{
    tableID = 0;
    seats = 0;
    status = "Available";
}

Table::Table(int id, int seats, string status)
{
    tableID = id;
    this->seats = seats;
    this->status = status;
}

void Table::setTableID(int id)
{
    tableID = id;
}

void Table::setSeats(int seats)
{
    this->seats = seats;
}

void Table::setStatus(string status)
{
    this->status = status;
}

int Table::getTableID()
{
    return tableID;
}

int Table::getSeats()
{
    return seats;
}

string Table::getStatus()
{
    return status;
}

void Table::displayTable()
{
    cout << "---------------------------------------------" << endl;
    cout << "Table ID : " << tableID << endl;
    cout << "Seats    : " << seats << endl;
    cout << "Status   : " << status << endl;
    cout << "---------------------------------------------" << endl;
}
