#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class User
{
protected:
    string username;
    string password;

public:
    User();
    User(string username, string password);

    void setUsername(string username);
    void setPassword(string password);

    string getUsername();
    string getPassword();

    bool login(string username, string password);
};

#endif
