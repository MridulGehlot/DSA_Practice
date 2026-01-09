#include<stdio.h>
int main()
{
int flag[10]={0};
int arr[10]={76,12,92,-3,76,56,12,93,78,56};
//min 1 possible
int m[10]={1};
int e,f,maxi;
for(f=1;f<=9;f++)
{
for(e=0;e<f;e++)
{
if(arr[f]>arr[e])
{
int val=m[e]+1;
if(val>m[f]) m[f]=val;
}
}
}
maxi=0;
for(int i=0;i<=9;i++) if(m[i]>maxi) maxi=m[i];

printf("Maximum Length of increasing subsequnce is %d\n",maxi);
return 0;
}