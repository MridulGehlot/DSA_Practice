#include<bits/stdc++.h>
using namespace std;
int main()
{
int arr[20]={12,3,92,-3,76,54,12,93,78,45,56,23,89,51,20,88,30,44,62,10};
int last;
for(int i=0;i<=19;i++)
{
last=arr[i];
for(int j=i+1;j<=19;j++)
{
if(arr[j]>=last)
{
cout<<last<<" ";
last=arr[j];
}
}
cout<<last<<endl;
}
return 0;
}