#include<bits/stdc++.h>
using namespace std;
int main()
{
int flag[20]={0};
int arr[20]={12,3,92,-3,76,54,12,93,78,45,56,23,89,51,20,88,30,44,62,10};
int prev,e,f;
e=0;
while(e<=18)
{
if(flag[e]) 
{
e++;
continue;
}
prev=e;
f=e+1;
while(f<=19)
{
if(arr[f]>arr[prev])
{
cout<<arr[prev]<<" ";
prev=f;
flag[prev]=1;
}
f++;
}
if(prev>e) cout<<arr[prev]<<endl;
e++;
}
return 0;
}