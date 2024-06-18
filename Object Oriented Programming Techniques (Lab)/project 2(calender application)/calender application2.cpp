#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <chrono>
#include <thread>
#include <chrono>
#include <ctime>
using namespace std;


// Base class Calendar
class Calendar {
protected:
    int year;

public:
    // Constructor
    Calendar(int y) : year(y) {}
    
    // Function to check if a given year is a leap year
    bool isLeapYear() {
        return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }
    
    // Static function to display the current date
    static void displayCurrentDate() {
        auto now = chrono::system_clock::now();  // Get the current time point
        time_t currentTime = chrono::system_clock::to_time_t(now);  // Convert to time_t

        // Convert to tm struct for breaking down time components
        tm localTime;
        #ifdef _MSC_VER
        localtime_s(&localTime, &currentTime);  // Secure version for MSVC
        #else
        localTime = *localtime(&currentTime);   // POSIX version
        #endif

        // Print the current date
        cout << "Current Date: ";
        cout << (localTime.tm_year + 1900) << '-'
             << setw(2) << setfill('0') << (localTime.tm_mon + 1) << '-'
             << setw(2) << setfill('0') << localTime.tm_mday << endl;
    }
    
    // Function to get the number of days in a month
    int numberOfDays(int monthNumber) {
        if (monthNumber == 1) { // February
            return isLeapYear() ? 29 : 28;
        }
        vector<int> monthDays = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return monthDays[monthNumber];
    }

    // Function to print the month name
    string getMonthName(int monthNumber) {
        vector<string> months = {"January", "February", "March", "April", "May", "June",
                                 "July", "August", "September", "October", "November", "December"};
        return months[monthNumber];
    }

    // Function to calculate the day of the week for a given date
    int dayNumber(int day, int month, int year) {
        static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
        year -= month < 3;
        return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
    }

    // Virtual function to display the calendar
    virtual void displayCalendar() = 0; // Make this function pure virtual

    // Friend function for greeting
    friend void greeting(Calendar &cal);
};

// Derived class LeapYearCalendar
class LeapYearCalendar : public Calendar {
public:
    LeapYearCalendar(int y) : Calendar(y) {}

    // Override the displayCalendar function
    void displayCalendar() override {
        cout << "Calendar - " << year << endl;
        for (int month = 0; month < 12; month++) {
            cout << "\n------------" << getMonthName(month) << "------------\n";
            cout << " Sun Mon Tue Wed Thu Fri Sat\n";

            int days = numberOfDays(month);
            int current = dayNumber(1, month + 1, year);

            for (int k = 0; k < current; k++)
                cout << "    ";

            for (int day = 1; day <= days; day++) {
                printf("%4d", day);
                if (++current > 6) {
                    current = 0;
                    cout << endl;
                }
            }
            if (current)
                cout << endl;
        }
    }
};

// Multiple Inheritance - Derived class FileCalendar
class FileCalendar : public LeapYearCalendar {
public:
    FileCalendar(int y) : LeapYearCalendar(y) {}

    // Function to save the calendar to a file
    void saveToFile(const string &filename) {
        ofstream file(filename);
        if (file.is_open()) {
            file << "Calendar - " << year << endl;
            for (int month = 0; month < 12; month++) {
                file << "\n------------" << getMonthName(month) << "------------\n";
                file << " Sun Mon Tue Wed Thu Fri Sat\n";

                int days = numberOfDays(month);
                int current = dayNumber(1, month + 1, year);

                for (int k = 0; k < current; k++)
                    file << "    ";

                for (int day = 1; day <= days; day++) {
                    file << setw(4) << day;
                    if (++current > 6) {
                        current = 0;
                        file << endl;
                    }
                }
                if (current)
                    file << endl;
            }
            file.close();
            cout << "Calendar saved to '" << filename << "'." << endl;
        } else {
            cout << "Unable to open file." << endl;
        }
    }
};

// Implementation of friend function
void greeting(Calendar &cal) {
    cout << "Welcome to the Calendar of year " << cal.year << "!" << endl;
}

// Main function
int main() {
    while (true) {
        
         // Display welcome message
cout<<"============================================================================"<<endl;
    cout << "Welcome to Calendar Application" << endl;
cout<<"============================================================================"<<endl;
    // Pause for 3 seconds
    this_thread::sleep_for(chrono::seconds(3));
    
    // Display the current date
        Calendar::displayCurrentDate();
        
        int year;
        cout << "Enter year: ";
        cin >> year;

        FileCalendar myCalendar(year);
        greeting(myCalendar); // Greet the user

        // Check and print if the year is a leap year
        if (myCalendar.isLeapYear()) {
            cout << year << " is a leap year." << endl;
        } else {
            cout << year << " is not a leap year." << endl;
        }

        myCalendar.displayCalendar(); // Display the calendar

        // Ask the user if they want to save the calendar to a file
        char saveOption;
        cout << "Do you want to save the calendar to a file? (y/n): ";
        cin >> saveOption;
        if (saveOption == 'y' || saveOption == 'Y') {
            myCalendar.saveToFile("calendar.txt"); // Save to file
        }

        // Ask if the user wants to enter a new year or exit
        char continueOption;
        cout << "Do you want to enter a new year input or exit? (Enter 'n' for new input, 'e' to exit): ";
        cin >> continueOption;
        if (continueOption == 'e' || continueOption == 'E') {
            break; // Exit the loop and end the program
        }
    }

    return 0;
}

