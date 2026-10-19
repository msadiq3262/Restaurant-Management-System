
#include "BillingManager.h"

BillingManager::BillingManager()
{
    filename = "receipts.txt";
}

void BillingManager::generateBill()
{
    int orderID;

    cout << "\n========== GENERATE BILL ==========" << endl;
    cout << "Enter Order ID: ";
    cin >> orderID;

    if (cin.fail() || orderID <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid Order ID." << endl;
        return;
    }

    generateBillForOrder(orderID);
}

void BillingManager::generateBillForOrder(int orderID)
{
    OrderManager orderManager;
    MenuManager menuManager;

    ifstream ordersFile("orders.txt");

    if (!ordersFile)
    {
        cout << "Error: Could not open orders.txt" << endl;
        return;
    }

    int savedOrderID;
    int customerID;
    int foodID;
    int quantity;
    double total;
    string status;
    bool found = false;

    while (ordersFile >> savedOrderID
                      >> customerID
                      >> foodID
                      >> quantity
                      >> total)
    {
        ordersFile.ignore(10000, '\n');
        getline(ordersFile, status);

        if (savedOrderID == orderID)
        {
            found = true;
            break;
        }
    }

    ordersFile.close();

    if (!found)
    {
        cout << "Order not found!" << endl;
        return;
    }

    if (quantity <= 0 || total < 0)
    {
        cout << "Invalid order data." << endl;
        return;
    }

    double subtotal = total;
    double tax = subtotal * 0.05;
    double grandTotal = subtotal + tax;

    cout << fixed << setprecision(2);

    cout << "\n===================================" << endl;
    cout << "       MY RESTAURANT RECEIPT       " << endl;
    cout << "===================================" << endl;
    cout << "Order ID   : " << savedOrderID << endl;
    cout << "Customer ID: " << customerID << endl;
    cout << "Food ID    : " << foodID << endl;
    cout << "Quantity   : " << quantity << endl;
    cout << "Subtotal   : Rs. " << subtotal << endl;
    cout << "Tax (5%)   : Rs. " << tax << endl;
    cout << "Grand Total: Rs. " << grandTotal << endl;
    cout << "Status     : " << status << endl;
    cout << "===================================" << endl;
    cout << "Thank you for visiting!" << endl;

    ofstream file(filename.c_str(), ios::app);

    if (!file)
    {
        cout << "Error: Could not save receipt." << endl;
        return;
    }

    file << fixed << setprecision(2);
    file << "===================================\n";
    file << "       MY RESTAURANT RECEIPT       \n";
    file << "===================================\n";
    file << "Order ID   : " << savedOrderID << endl;
    file << "Customer ID: " << customerID << endl;
    file << "Food ID    : " << foodID << endl;
    file << "Quantity   : " << quantity << endl;
    file << "Subtotal   : Rs. " << subtotal << endl;
    file << "Tax (5%)   : Rs. " << tax << endl;
    file << "Grand Total: Rs. " << grandTotal << endl;
    file << "Status     : " << status << endl;
    file << "===================================\n\n";

    file.close();

    cout << "\nReceipt saved to receipts.txt" << endl;
}

