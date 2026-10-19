#include "User.h"

User::User()
{
    username = "";
    password = "";
}

User::User(string username, string password)
{
    this->username = username;
    this->password = password;
}

void User::setUsername(string username)
{
    this->username = username;
}

void User::setPassword(string password)
{
    this->password = password;
}

string User::getUsername()
{
    return username;
}

string User::getPassword()
{
    return password;
}

bool User::login(string username, string password)
{
    if (this->username == username &&
        this->password == password)
    {
        return true;
    }

    return false;
}
