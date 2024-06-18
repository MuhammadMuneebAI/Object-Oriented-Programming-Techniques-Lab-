#include <iostream>
#include <string>

using namespace std;

struct Item 
{
    string name;
    int quantity;
    double price;
};

void displayMenu();
void addItem(Item* &inventory, int &size);
void displayItems(const Item* inventory, int size);
void deleteItem(Item* &inventory, int &size);

int main() {
    Item* inventory = nullptr;  // Dynamic array to hold the inventory items
    int size = 0;  // Variable to hold the size of the dynamic array
    int choice;  // Variable to hold the user's menu choice

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addItem(inventory, size);
                break;
            case 2:
                displayItems(inventory, size);
                break;
            case 3:
                deleteItem(inventory, size);
                break;
            case 4:
                delete[] inventory;
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

void displayMenu() {
    cout << "Inventory Management System" << endl;
    cout << "1. Add Item" << endl;
    cout << "2. Display Items" << endl;
    cout << "3. Delete Item" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

void addItem(Item* &inventory, int &size) {
    Item newItem;
    cout << "Enter the name of the item: ";
    cin >> newItem.name;
    cout << "Enter the quantity: ";
    cin >> newItem.quantity;
    cout << "Enter the price: ";
    cin >> newItem.price;

    Item* temp = new Item[size + 1];
    for (int i = 0; i < size; ++i) {
        temp[i] = inventory[i];
    }
    temp[size] = newItem;

    delete[] inventory;
    inventory = temp;
    ++size;

    cout << "Item added successfully!" << endl;
}

void displayItems(const Item* inventory, int size) {
    cout << "Inventory Items:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Name: " << inventory[i].name << ", Quantity: " << inventory[i].quantity << ", Price: " << inventory[i].price << endl;
    }
}

void deleteItem(Item* &inventory, int &size) {
    string name;
    cout << "Enter the name of the item to delete: ";
    cin >> name;

    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (inventory[i].name == name) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Item not found!" << endl;
        return;
    }

    Item* temp = new Item[size - 1];
    for (int i = 0, j = 0; i < size; ++i) {
        if (i != index) {
            temp[j++] = inventory[i];
        }
    }

    delete[] inventory;
    inventory = temp;
    --size;

    cout << "Item deleted successfully!" << endl;
}
