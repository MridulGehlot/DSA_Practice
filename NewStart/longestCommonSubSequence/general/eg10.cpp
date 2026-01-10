#include<iostream>
using namespace std;
int main()
{
char arr[4]={'a','b','c','d'};
int x,e1,e2,e3,e4;
x=1;
x=x<<4;
x-=1;
for(int i=0;i<=x;i++)
{
cout<<"(";
e1=(i>>0)&1;
e2=(i>>1)&1;
e3=(i>>2)&1;
e4=(i>>3)&1;
if(e1) cout<<arr[0];
if(e2) cout<<arr[1];
if(e3) cout<<arr[2];
if(e4) cout<<arr[3];
cout<<") ";
}
return 0;
}