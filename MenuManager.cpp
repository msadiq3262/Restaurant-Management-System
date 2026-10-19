#include "MenuManager.h"

MenuManager::MenuManager()
{
    filename = "menu.txt";

    loadFoods();
}

void MenuManager::loadFoods()
{
    std::ifstream file(filename.c_str());

    if (!file)
    {
        return;
    }

    int id;
    string name;
    string category;
    double price;

    while (file >> id)
    {
        file.ignore();

        getline(file, name);
        getline(file, category);

        file >> price;
        file.ignore();

        Food food(id, name, category, price);

        foods.push_back(food);
    }

    file.close();
}

void MenuManager::saveFoods()
{
    std::ofstream file(filename.c_str());

    if (!file)
    {
        cout << "Error: Could not open menu file!" << endl;
        return;
    }

    for (int i = 0; i < foods.size(); i++)
    {
        file << foods[i].getFoodID() << endl;
        file << foods[i].getFoodName() << endl;
        file << foods[i].getCategory() << endl;
        file << foods[i].getPrice() << endl;
    }

    file.close();
}

void MenuManager::addFood()
{
    int id;
    string name;
    string category;
    double price;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "                   ADD FOOD                       " << endl;
    cout << "==================================================" << endl;

    cout << "Enter Food ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Food Name: ";
    getline(cin, name);

    cout << "Enter Category: ";
    getline(cin, category);

    cout << "Enter Price: ";
    cin >> price;

    Food food(id, name, category, price);

    foods.push_back(food);

    saveFoods();

    cout << endl;
    cout << "Food added successfully!" << endl;
}

void MenuManager::viewFoods()
{
    cout << endl;
    cout << "==================================================" << endl;
    cout << "                   MENU ITEMS                     " << endl;
    cout << "==================================================" << endl;

    if (foods.empty())
    {
        cout << "No food items found." << endl;
        return;
    }

    for (int i = 0; i < foods.size(); i++)
    {
        foods[i].displayFood();
    }
}

void MenuManager::searchFood()
{
    int id;
    bool found = false;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "                  SEARCH FOOD                     " << endl;
    cout << "==================================================" << endl;

    cout << "Enter Food ID: ";
    cin >> id;

    for (int i = 0; i < foods.size(); i++)
    {
        if (foods[i].getFoodID() == id)
        {
            cout << endl;
            cout << "Food found!" << endl;
            foods[i].displayFood();

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << endl;
        cout << "Food not found!" << endl;
    }
}

void MenuManager::updateFood()
{
    int id;
    bool found = false;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "                  UPDATE FOOD                     " << endl;
    cout << "==================================================" << endl;

    cout << "Enter Food ID to update: ";
    cin >> id;

    for (int i = 0; i < foods.size(); i++)
    {
        if (foods[i].getFoodID() == id)
        {
            string name;
            string category;
            double price;

            cin.ignore();

            cout << "Enter new Food Name: ";
            getline(cin, name);

            cout << "Enter new Category: ";
            getline(cin, category);

            cout << "Enter new Price: ";
            cin >> price;

            foods[i].setFoodName(name);
            foods[i].setCategory(category);
            foods[i].setPrice(price);

            saveFoods();

            cout << endl;
            cout << "Food updated successfully!" << endl;

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << endl;
        cout << "Food not found!" << endl;
    }
}

void MenuManager::deleteFood()
{
    int id;
    bool found = false;

    cout << endl;
    cout << "==================================================" << endl;
    cout << "                  DELETE FOOD                     " << endl;
    cout << "==================================================" << endl;

    cout << "Enter Food ID to delete: ";
    cin >> id;

    for (int i = 0; i < foods.size(); i++)
    {
        if (foods[i].getFoodID() == id)
        {
            foods.erase(foods.begin() + i);

            saveFoods();

            cout << endl;
            cout << "Food deleted successfully!" << endl;

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << endl;
        cout << "Food not found!" << endl;
    }
}

bool MenuManager::getFoodByID(int id, Food &food)
{
    for (int i = 0; i < foods.size(); i++)
    {
        if (foods[i].getFoodID() == id)
        {
            food = foods[i];
            return true;
        }
    }

    return false;
}
void MenuManager::showMenu()
{
    int choice;

    while (true)
    {
        cout << endl;
        cout << "==================================================" << endl;
        cout << "                MENU MANAGEMENT                   " << endl;
        cout << "==================================================" << endl;
        cout << "1. Add Food" << endl;
        cout << "2. View Food" << endl;
        cout << "3. Search Food" << endl;
        cout << "4. Update Food" << endl;
        cout << "5. Delete Food" << endl;
        cout << "6. Back" << endl;
        cout << "==================================================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addFood();
                break;

            case 2:
                viewFoods();
                break;

            case 3:
                searchFood();
                break;

            case 4:
                updateFood();
                break;

            case 5:
                deleteFood();
                break;

            case 6:
                return;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
