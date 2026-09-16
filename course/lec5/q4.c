//Find Single Number
#include<stdio.h>
int main()
{
int arr[5]={1,2,3,1,2};
int res=0;
for(int i=0;i<5;i++) res^=arr[i];
printf("Single Number is %d",res);
return 0;
}