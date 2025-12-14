#include<stdio.h>
int isLeap(int x)
{
if(x%400==0) return 1;
else if(x%100==0) return 0;
else if(x%4==0) return 1;
else return 0;
}
int main()
{
int year;
printf("Enter a Year : ");
scanf("%d",&year);
if(isLeap(year)) printf("Leap Year");
else printf("Not a leap year");
return 0;
}