#include<stdio.h>
int main()
{
int arr[10]={6,4,12,3,32,76,54,19,27,62};
int count=0;
for(int i=0;i<10;i++)
{
for(int j=i+1;j<10;j++) if(arr[i]>arr[j]) count++;
}
printf("Total Number of inversions - %d\n",count);
return 0;
}