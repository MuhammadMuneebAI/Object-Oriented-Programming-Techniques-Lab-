#include<iostream>
using namespace std;
class add
{
	private:
		int inum1,inum2,inum3;
	public:
		void input(int ivar1,int ivar2)
{
	inum1=ivar1;
	inum2=ivar2;
}
   void sum()
   {
   	inum3=inum1+inum2;
   }
   void display()
   {
   	cout<<"sum of two variables are:"<<inum3;
   }
};
int main()
{
	add A;
	int x,y;
	cout<<"enter the values of x and y:";
	cin>>x>>y;
	A.input(x,y);
	A.sum();
	A.display();
}
