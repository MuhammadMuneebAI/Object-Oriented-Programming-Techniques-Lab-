#include <iostream>

using namespace std;

class TollBooth {
private:
    unsigned int car;
    double money;

public:
    TollBooth() : car(0), money(0) {}

    void payingCar() {
        car++;
        money += 0.50;  // Assuming the toll is 0.50 for a paying car
    }

    void nopayCar() {
        car++;
    }

    void display() {
        cout << "\nTotal Money Collected On TollBooth = $" << money << endl;
    }

    void get() {
        cout << "Total Cars On TollBooth = " << car << endl;
    }
};

int main() {
    char x;
    TollBooth d;

    while (true) {
        cout << "Enter 1 for Toll Paying Cars, 2 for Non-Toll Paying Cars, or 3 to Exit: ";
        cin >> x;

        switch (x) {
        case '1':
            d.payingCar();
            d.display();
            d.get();
            break;
        case '2':
            d.nopayCar();
            d.display();
            d.get();
            break;
        case '3':
            cout << "Exiting... Final Report:\n";
            d.display();
            d.get();
            return 0;  // Exit the program
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

