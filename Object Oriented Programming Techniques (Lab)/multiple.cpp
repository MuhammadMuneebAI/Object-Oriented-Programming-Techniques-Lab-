#include<iostream>
using namespace std;

class person
{	
public:
	string name;
	int age;
	string gender;	
	void getdata()
	{
		cout<<"Enter the Person Name :";
		cin>>name;
		cout<<"Enter the Person age :";
		cin>>age;
		cout<<"Enter the Person gender :";
		cin>>gender;
	}
	
};
class employee
{
public:
	string employername;
	int dailywages;	
	void inputdata()
	{
		cout<<"Enter the employee Name :";
		cin>>employername;
		cout<<"Enter the employee daily wages :";
		cin>>dailywages;
	}
};
class teacher:public employee,public person
{
public:
	char grade;
	void getgrade()
	{
	cout<<"Enter the grade :";
	cin>>grade;
	}
void display()
 {
	cout<<"person name :"<<name;
	cout<<"Age :"<<age;
	cout<<"Gender :"<<gender;
	cout<<"employeename :"<<employername;
	cout<<"dailywages :"<<dailywages;
	cout<<"teacher grade :"<<grade;
 }
};
int main()
{
	teacher t;
	t.getdata();
	t.inputdata();
	t.getgrade();
	t.display();
	return 0;
}

