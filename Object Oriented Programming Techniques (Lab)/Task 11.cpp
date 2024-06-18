#include<iostream>
using namespace std;

class Date1
{
	public:
	
	int date;
	int month;
	int year;
	Date1(int birthdate,int birthmonth,int birthyear)
	{
        date=birthdate;
		month=birthmonth;
		year=birthyear; 
	};
void display()
{
	cout<<date;
	cout<<"/"<<month;
	cout<<"/"<<year;
}
};
int main()
{
	Date1 m(13,11,2001);
	m.display();
	
   return 0;	
}
