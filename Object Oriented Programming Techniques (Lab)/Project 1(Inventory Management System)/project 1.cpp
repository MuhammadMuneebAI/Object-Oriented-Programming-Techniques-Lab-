#include <iostream>
#include <string>

using namespace std;

class InventoryManager {
public:
    InventoryManager();
    ~InventoryManager();
    void run();

private:
    struct Item {
        string name;
        int quantity;
        double price;
    };

    Item* inventory;
    int size;

    void displayMenu();
    void addItem();
    void displayItems();
    void deleteItem();
};

InventoryManager::InventoryManager() {
    inventory = nullptr;
    size = 0;
}

InventoryManager::~InventoryManager() {
    if (inventory) {
        delete[] inventory;
    }
}

void InventoryManager::run() {
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                deleteItem();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void InventoryManager::displayMenu() {
    cout << "Inventory Management System" << endl;
    cout << "1. Add Item" << endl;
    cout << "2. Display Items" << endl;
    cout << "3. Delete Item" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

void InventoryManager::addItem() {
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

void InventoryManager::displayItems() {
    cout << "Inventory Items:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Name: " << inventory[i].name << ", Quantity: " << inventory[i].quantity << ", Price: " << inventory[i].price << endl;
    }
}

void InventoryManager::deleteItem() {
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

    cout << "Item deleted successfully!" << endl;
}

int main() {
    InventoryManager manager;
    manager.run();

    return 0;
}

