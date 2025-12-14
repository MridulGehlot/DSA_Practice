#include<stdio.h>
int main()
{
int x,y,temp;
printf("Enter a Number : ");
scanf("%d",&x);
temp=x;
y=0;
while(temp>0)
{
y=(y*10)+temp%10;
temp/=10;
}
printf("Original Number = %d\n",x);
printf("Reverse Number = %d",y);
return 0;
}