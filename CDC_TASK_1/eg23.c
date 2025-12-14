#include<stdio.h>
int main()
{
int x,y;
printf("Enter a Number : ");
scanf("%d",&x);
y=x;
int sum=0;
while(y>0)
{
sum+=y%10;
y/=10;
}
printf("Sum of digits = %d",sum);
return 0;
}