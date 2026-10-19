#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Food.h"

using namespace std;

class MenuManager
{
private:
    vector<Food> foods;
    string filename;

    void loadFoods();
    void saveFoods();

public:

    // Constructor
    MenuManager();

    // Menu functions
    void addFood();
    void viewFoods();
    void searchFood();
    void updateFood();
    void deleteFood();

    // Find food by ID
    bool getFoodByID(int id, Food &food);

    // Show menu
    void showMenu();
};

#endif
