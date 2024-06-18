#include <iostream>
#include <string>
using namespace std;
class Vehicle 
{
protected:
    std::string make;
    std::string model;
    int year;

public:
    Vehicle(string m,string mo, int y) : make(m), model(mo), year(y) {}

    void display()
    {
    cout << "Make: " << make << ", Model: " << model << ", Year: " << year <<endl;
    }
};

class Car : public Vehicle 
{
protected:
    int seats;
    bool airConditioning;

public:
    Car(string m,string mo, int y, int s, bool ac) : Vehicle(m, mo, y), seats(s), airConditioning(ac) {}

    void display() 
	{
        Vehicle::display();
        cout << "Seats: " << seats << ", Air Conditioning: " << (airConditioning ? "Yes" : "No") <<endl;
    }

};

class LuxuryCar : public Car 
{
private:
    bool heatedSeats;
    bool bluetooth;

public:
    LuxuryCar(string m,string mo, int y, int s, bool ac, bool hs, bool bt)
        : Car(m, mo, y, s, ac), heatedSeats(hs), bluetooth(bt) {}

    void display() 
	{
        Car::display();
       cout << "Heated Seats: " << (heatedSeats ? "Yes" : "No") << ", Bluetooth: " << (bluetooth ? "Yes" : "No") << std::endl;
    }
};

int main() 
{
    Vehicle vehicle("Generic Make", "Generic Model", 2020);
    vehicle.display();

    Car car("Toyota", "Corolla", 2021, 5, true);
    car.display();

    LuxuryCar luxuryCar("Mercedes", "S-Class", 2022, 5, true, true, true);
    luxuryCar.display();

    return 0;
}

