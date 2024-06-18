#include<iostream>
#include<conio.h>
using namespace std;
class baseclass
{
	int num1;
	
	
public:
	void setint(int n);
	int getInt();
};
class derivedclass : public baseclass
{
	int num2;
public:
	void setj(int n);
	int mul();
};

void baseclass::setint(int n)
{
	num1 =n;
}
int baseclass::getInt()
{
	return num1;
}
void derivedclass::setj(int n)
{
	num2=n;
}
int derivedclass::mul()
{
	cout<<"Result=";
	return (num2 * getInt());
}
int main()
{
	derivedclass ob;
	
	ob.setint(10);
	ob.setj(4);
	
	cout<<ob.mul()<<endl;
	system("pause");
	return 0;
}
