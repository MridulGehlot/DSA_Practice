#include<stdio.h>
int main()
{
int arr[10]={12,45,23,65,88,78,22,19,73,46};
int mini=arr[0];
for(int i=0;i<10;i++) if(arr[i]<mini) mini=arr[i];
printf("minimum = %d\n",mini);
return 0;
}