#include <iostream>
using namespace std;

struct Book {
    int id;
    double price;
    int pages;
};

int main() {
    Book books[3];
    for (int i = 0; i < 3; i++) {
        cout << "Enter the data for book " << i + 1 << endl;
        cout << "Enter ID: ";
        cin >> books[i].id;

        cout << "Enter price: ";
        cin >> books[i].price;

        cout << "Enter pages: ";
        cin >> books[i].pages;
    }

    int mostExpensiveIndex = 0;
    for (int i = 1; i < 3; i++) {
        if (books[i].price > books[mostExpensiveIndex].price) {
            mostExpensiveIndex = i;
        }
    }
    cout << "\nThe most costly book is book " << mostExpensiveIndex + 1;

    return 0;
}


