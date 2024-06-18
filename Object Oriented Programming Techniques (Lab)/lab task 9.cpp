#include <iostream>
using namespace std;

class MyRecord 
{
private:
    double oopMarks;
    double attendance;

public:
    MyRecord() 
	{
        oopMarks = 0.0;
        attendance = 0.0;
    }
    void inputMarks() 
	{
        cout << "Enter OOP Marks (out of 100): ";
        cin >> oopMarks;
    }
    void inputAttendance() 
	{
        cout << "Enter Attendance (out of 15): ";
        cin >> attendance;
    }
    double percentage() 
	{
        return (oopMarks / 100) * 100;
    }
    double attendanceCalculator() 
	{
        return (attendance / 15) * 100;
    }
    void display() 
	{
        cout << "OOP Marks: " << oopMarks << "/100" << endl;
        cout << "Attendance: " << attendance << "/15" << endl;
        cout << "Percentage: " << percentage() << "%" << endl;
        cout << "Attendance Percentage: " << attendanceCalculator() << "%" << endl;
    }
};

int main() 
{
    MyRecord record;

    record.inputMarks();
    record.inputAttendance();
    record.display();

    return 0;
}

