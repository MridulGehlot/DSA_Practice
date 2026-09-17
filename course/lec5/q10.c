/*
Determine Mountain Array

-Inf [2,3 ,9(peak) ,6,5,1] -Inf
return T/F
*/
#include<stdio.h>
int main()
{
int arr[7]={2,3,9,6,5,1,6};
bool ans=true;
int i=1,n=7;

//left to peak
while(i<n && arr[i]>=arr[i-1])
{
++i;
}

int peak=i-1;

//Now Move From next to peak till right end
while(i<n && arr[i]<=arr[i-1])
{
++i;
}

if(i==n) ans=true;
else ans=false;

printf("Array Is Mountain array %d\n",ans);
printf("Peak Index is %d",peak);
return 0;
}