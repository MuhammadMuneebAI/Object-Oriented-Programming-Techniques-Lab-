#include<iostream>
using namespace std;
void duplicate (int& var1, int& var2, int& var3)
{
	var1*=2;
	var2*=2;
	var3*=2;
}
int main()
{
	int a=1,b=3,c=7;
	duplicate(a,b,c);
	cout<<"a="<< a <<", b=" << b <<", c=" << c;
	return 0;
}

