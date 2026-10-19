#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>

using namespace std;

class Food
{
private:
    int foodID;
    string foodName;
    string category;
    double price;

public:
    Food();
    Food(int id, string name, string category, double price);

    void setFoodID(int id);
    void setFoodName(string name);
    void setCategory(string category);
    void setPrice(double price);

    int getFoodID();
    string getFoodName();
    string getCategory();
    double getPrice();

    void displayFood();
};

#endif
