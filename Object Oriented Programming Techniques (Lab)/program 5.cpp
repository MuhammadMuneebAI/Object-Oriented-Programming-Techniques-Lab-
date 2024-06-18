#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>

// Custom exception for handling library-related errors
class LibraryException : public std::exception {
private:
    std::string message;
public:
    LibraryException(const std::string& msg) : message(msg) {}
    const char* what() const throw() {
        return message.c_str();
    }
};

// Book class (Encapsulation & Abstraction)
class Book {
private:
    std::string id;
    std::string title;
    bool isBorrowed;

public:
    Book(const std::string& bookId, const std::string& bookTitle) 
        : id(bookId), title(bookTitle), isBorrowed(false) {}

    void borrowBook() {
        if(isBorrowed) {
            throw LibraryException("Book is already borrowed.");
        }
        isBorrowed = true;
    }

    void returnBook() {
        if(!isBorrowed) {
            throw LibraryException("Book was not borrowed.");
        }
        isBorrowed = false;
    }

    std::string getId() const { return id; }
    std::string getTitle() const { return title; }
    bool getIsBorrowed() const { return isBorrowed; }
    
    // Polymorphism (virtual function)
    virtual void display() const {
        std::cout << "Book ID: " << id << ", Title: " << title 
                  << ", Borrowed: " << (isBorrowed ? "Yes" : "No") << std::endl;
    }
};

// Library class (Encapsulation)
class Library {
private:
    std::unordered_map<std::string, std::unique_ptr<Book>> books;

public:
    void addBook(const std::string& id, const std::string& title) {
        if(books.find(id) != books.end()) {
            throw LibraryException("Book with this ID already exists.");
        }
        books[id] = std::make_unique<Book>(id, title);
    }

    void removeBook(const std::string& id) {
        if(books.find(id) == books.end()) {
            throw LibraryException("Book with this ID does not exist.");
        }
        books.erase(id);
    }

    void borrowBook(const std::string& id) {
        if(books.find(id) == books.end()) {
            throw LibraryException("Book with this ID does not exist.");
        }
        books[id]->borrowBook();
    }

    void returnBook(const std::string& id) {
        if(books.find(id) == books.end()) {
            throw LibraryException("Book with this ID does not exist.");
        }
        books[id]->returnBook();
    }

    // Demonstrating polymorphism by calling display on Book objects
    void displayBooks() const {
        for (const auto& pair : books) {
            pair.second->display();
        }
    }
};

// Inheritance: Derived class from Book (optional)
class SpecialBook : public Book {
public:
    SpecialBook(const std::string& bookId, const std::string& bookTitle)
        : Book(bookId, bookTitle) {}

    void display() const override {
        std::cout << "Special Book -- ";
        Book::display();
    }
};

int main() {
    Library lib;

    try {
        lib.addBook("1", "The C++ Programming Language");
        lib.addBook("2", "Effective Modern C++");

        lib.displayBooks();

        lib.borrowBook("1");
        lib.borrowBook("2");

        // Uncommenting the next line will throw an exception because the book is already borrowed
        // lib.borrowBook("1");

        lib.returnBook("1");
        // Uncommenting the next line will throw an exception because the book is not borrowed
        // lib.returnBook("1");

        lib.displayBooks();

        lib.removeBook("2");

        lib.displayBooks();
        
        // Adding and displaying a SpecialBook
        lib.addBook("3", "Special C++ Insights");
        lib.displayBooks();

    } catch (const LibraryException& e) {
        std::cerr << "Library error: " << e.what() << std::endl;
    }

    return 0;
}

