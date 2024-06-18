#include <iostream>
#include <unordered_map>
#include <stdexcept>

class Library {
private:
    std::unordered_map<std::string, bool> books;

public:
    void addBook(const std::string& bookID) {
        if (books.find(bookID) != books.end()) {
            throw std::invalid_argument("Book with ID " + bookID + " already exists.");
        }
        books[bookID] = true;  // true indicates the book is available
    }

    void removeBook(const std::string& bookID) {
        if (books.find(bookID) == books.end()) {
            throw std::invalid_argument("Book with ID " + bookID + " does not exist.");
        }
        books.erase(bookID);
    }

    void borrowBook(const std::string& bookID) {
        if (books.find(bookID) == books.end()) {
            throw std::invalid_argument("Book with ID " + bookID + " does not exist.");
        }
        if (!books[bookID]) {
            throw std::invalid_argument("Book with ID " + bookID + " is not available for borrowing.");
        }
        books[bookID] = false;  // false indicates the book is borrowed
    }

    void returnBook(const std::string& bookID) {
        if (books.find(bookID) == books.end()) {
            throw std::invalid_argument("Book with ID " + bookID + " does not exist.");
        }
        books[bookID] = true;
    }
};

int main() {
    Library library;

    try {
        library.addBook("123");
        library.borrowBook("123");

        // Try to borrow the same book again
        library.borrowBook("123");
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

