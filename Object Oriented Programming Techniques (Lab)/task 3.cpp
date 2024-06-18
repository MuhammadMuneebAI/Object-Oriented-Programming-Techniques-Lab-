#include<iostream>
using namespace std;
int main()
{
int first, second;
int *myptr;
myptr =&first;

*myptr = 10;
myptr = &second;
*myptr = 20;
cout <<"First Value is" <<first<<endl;
cout <<"Second Value is" <<second<<endl;
return 0;
}
