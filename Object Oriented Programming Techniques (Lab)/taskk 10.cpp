#include<iostream>
using namespace std;

class student
{
	public:
	
	string name;
	int age;
	student()
	{
		name="unkown\n";
		age=0;
	};
void input()
{
	cout<<"Enter your name and age : ";
	cin>>name>>age;
}
void display()
{
	cout<<"name : "<<name<<endl;
	cout<<"age : "<<age<<endl;
}
};
int main()
{
	student m;
	m.display();
	m.input();
	m.display();

   return 0;	
}
