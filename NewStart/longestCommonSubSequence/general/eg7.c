#include<stdio.h>
int main()
{
int flag[10]={0};
int arr[10]={76,12,92,-3,76,56,12,93,78,56};
int prev,e,f,count,maxi;
e=0;
maxi=0;
while(e<=8)
{
if(flag[e]) 
{
e++;
continue;
}
prev=e;
f=e+1;
count=0;
while(f<=9)
{
if(arr[f]>arr[prev])
{
count++;
prev=f;
flag[prev]=1;
}
f++;
}
if(prev>e)
{
count++;
if(count>maxi) maxi=count;
}
e++;
}
printf("Maximum Length of increasing subsequnce is %d\n",maxi);
return 0;
}