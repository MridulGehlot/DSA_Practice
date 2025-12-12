#include<stdio.h>
int main()
{
int arr[10]={12,45,23,65,88,78,22,19,73,46};
int maxi=arr[0];
for(int i=0;i<10;i++) if(arr[i]>maxi) maxi=arr[i];
printf("max = %d\n",maxi);
return 0;
}