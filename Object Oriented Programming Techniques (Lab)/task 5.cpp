#include<iostream>
using namespace std;
struct date
{
	int date;
	int month;
	int year;
};
int main()
{
	date birthDate;
	cout<<"Enter date of birth ";
	cin>>birthDate.date;
	cout<<"Enter month of birth ";
	cin>>birthDate.month;
	cout<<"Enter year of birth ";
	cin>>birthDate.year;
	
	cout<<birthDate.date<<"/"<<birthDate.month <<"/"<<birthDate.year;
	return 0;
}
