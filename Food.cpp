#include "Food.h"

Food::Food()
{
    foodID = 0;
    foodName = "";
    category = "";
    price = 0.0;
}

Food::Food(int id, string name, string category, double price)
{
    this->foodID = id;
    this->foodName = name;
    this->category = category;
    this->price = price;
}

void Food::setFoodID(int id)
{
    foodID = id;
}

void Food::setFoodName(string name)
{
    foodName = name;
}

void Food::setCategory(string category)
{
    this->category = category;
}

void Food::setPrice(double price)
{
    this->price = price;
}

int Food::getFoodID()
{
    return foodID;
}

string Food::getFoodName()
{
    return foodName;
}

string Food::getCategory()
{
    return category;
}

double Food::getPrice()
{
    return price;
}

void Food::displayFood()
{
    cout << "---------------------------------------------" << endl;
    cout << "Food ID   : " << foodID << endl;
    cout << "Food Name : " << foodName << endl;
    cout << "Category  : " << category << endl;
    cout << "Price     : " << price << endl;
    cout << "---------------------------------------------" << endl;
}
