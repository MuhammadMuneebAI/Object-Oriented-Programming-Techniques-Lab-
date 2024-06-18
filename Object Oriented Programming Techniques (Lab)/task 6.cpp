#include <iostream>
using namespace std;

struct Book {
    int bookId;
    double price;
    int pages;
};

void initializeBook(Book &book) {
    cout << "Enter Book ID: ";
    cin >> book.bookId;
    cout << "Enter Price: ";
    cin >> book.price;
    cout << "Enter Number of Pages: ";
    cin >> book.pages;
}

void displayBook(const Book &book) {
    cout << "Book ID: " << book.bookId << endl;
    cout << "Price: $" << book.price << endl;
    cout << "Pages: " << book.pages << " pages" << endl;
}

int main() {
    int numBooks;
    cout << "Enter the number of books: ";
    cin >> numBooks;

    if (numBooks <= 0) {
        cout << "Invalid number of books. Exiting program." << endl;
        return 1;
    }

    Book *books = new Book[numBooks];

    for (int i = 0; i < numBooks; i++) {
        cout << "Enter details for Book " << i + 1 << ":" << endl;
        initializeBook(books[i]);
    }

    // Find the most costly book
    double maxPrice = books[0].price;
    int maxPriceIndex = 0;
    for (int i = 1; i < numBooks; i++) {
        if (books[i].price > maxPrice) {
            maxPrice = books[i].price;
            maxPriceIndex = i;
        }
    }

    cout << "\nDetails of the most costly book:" << endl;
    displayBook(books[maxPriceIndex]);

    delete[] books; // Free dynamically allocated memory
    return 0;
}

