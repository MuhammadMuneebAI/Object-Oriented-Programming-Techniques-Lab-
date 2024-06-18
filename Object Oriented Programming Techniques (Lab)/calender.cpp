#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;
class Month {
private:
    int month;
    int year;

public:
    Month(int m, int y) : month(m), year(y) {}

    int getFirstDayOfMonth() {
        struct tm timeStruct = {};
        timeStruct.tm_year = year - 1900;
        timeStruct.tm_mon = month - 1;
        timeStruct.tm_mday = 1;

        mktime(&timeStruct);

        return timeStruct.tm_wday;
    }

    int getNumberOfDays() {
        int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
            return 29;

        return daysInMonth[month - 1];
    }
};

class Calendar {
public:
    static void printMonth(int year, int month) {
        Month m(month, year);

        cout << "Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

        int firstDay = m.getFirstDayOfMonth();
        int daysInMonth = m.getNumberOfDays();

        for (int i = 0; i < firstDay; i++) {
            cout << "     ";
        }

        for (int day = 1; day <= daysInMonth; day++) {
            cout << setw(3) << day << "  ";
            if ((day + firstDay) % 7 == 0) {
                cout << "\n";
            }
        }
        cout << "\n";
    }

    static void printYear(int year) {
        for (int month = 1; month <= 12; month++) {
            cout << "\nMonth: " << month << "\n";
            printMonth(year, month);
        }
    }
};

int main() {
cout <<"============================================="<<endl;
cout <<"      WELCOME TO CALENDER APPLICATION"<<endl;
cout <<"============================================="<<endl;
    int year, month;

    cout << "Enter year: ";
    cin >> year;

    cout << "Enter month (1-12): ";
    cin >> month;

    if (month < 1 || month > 12) {
        cout << "Invalid month. Please enter a month between 1 and 12.\n";
    } else {
        Calendar::printMonth(year, month);
    }
    return 0;
}

