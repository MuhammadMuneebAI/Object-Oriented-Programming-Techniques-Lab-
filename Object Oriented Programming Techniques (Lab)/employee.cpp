#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

// Define the Employee structure
struct Employee {
    int code;
    string name;
    tm dateOfJoining;  // Using 'tm' structure for date
};

// Function to calculate the difference in years between two dates
int calculateYears(const tm &startDate, const tm &endDate) {
    int years = endDate.tm_year - startDate.tm_year;
    if (endDate.tm_mon < startDate.tm_mon || 
        (endDate.tm_mon == startDate.tm_mon && endDate.tm_mday < startDate.tm_mday)) {
        years--;
    }
    return years;
}

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    vector<Employee> employees(n);

    // Input data for each employee
    for (int i = 0; i < n; ++i) {
        cout << "Enter data for employee " << i + 1 << endl;
        cout << "Code: ";
        cin >> employees[i].code;
        cin.ignore();  // Ignore newline character after integer input
        cout << "Name: ";
        getline(cin, employees[i].name);
        cout << "Date of Joining (dd mm yyyy): ";
        cin >> employees[i].dateOfJoining.tm_mday >> employees[i].dateOfJoining.tm_mon 
            >> employees[i].dateOfJoining.tm_year;
        employees[i].dateOfJoining.tm_mon--;  // tm_mon is 0-11
        employees[i].dateOfJoining.tm_year -= 1900;  // tm_year is years since 1900
    }

    // Get the current date from the user
    tm currentDate;
    cout << "Enter the current date (dd mm yyyy): ";
    cin >> currentDate.tm_mday >> currentDate.tm_mon >> currentDate.tm_year;
    currentDate.tm_mon--;  // tm_mon is 0-11
    currentDate.tm_year -= 1900;  // tm_year is years since 1900

    // Display names of employees with tenure of 3 or more years
    cout << "Employees with a tenure of 3 or more years:" << endl;
    for (const auto &employee : employees) {
        if (calculateYears(employee.dateOfJoining, currentDate) >= 3) {
            cout << employee.name << endl;
        }
    }

    return 0;
}

