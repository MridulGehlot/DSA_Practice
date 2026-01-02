//Kadane's Algo
#include<stdio.h>
int max(int a,int b)
{
if(a>b) return a;
else return b;
}
int main()
{
int arr[10]={10,-3,7,6,-2,4,3,9,-5,12};
int localMax,globalMax;
for(int i=0;i<=9;i++)
{
localMax=max(localMax+arr[i],arr[i]);
globalMax=max(globalMax,localMax);
}
printf("Answer - %d",globalMax);
return 0;
}