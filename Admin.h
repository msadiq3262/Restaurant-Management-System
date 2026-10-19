#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "MenuManager.h"
#include "CustomerManager.h"
#include "TableManager.h"
#include "OrderManager.h"
#include "BillingManager.h"
#include "ReportManager.h"

class Admin : public User
{
public:
    Admin();
    Admin(string username, string password);

    void showAdminDashboard();
};

#endif
