#include<stdio.h>
int main()
{
int x,count;
printf("Enter a Number : ");
scanf("%d",&x);
while(x>0)
{
count++;
x/=10;
}
printf("NUmber of digits = %d",count);
return 0;
}