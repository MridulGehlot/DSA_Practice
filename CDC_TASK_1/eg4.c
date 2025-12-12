#include<stdio.h>
int main()
{
int x,y;
x=15;
y=250;
printf("Before Swapping\n");
printf("x = %d , y=%d\n",x,y);

//using Temp Vairable
printf("----------TEMP VAR---------\n");
int temp;
temp=x;
x=y;
y=temp;
printf("x = %d , y=%d\n",x,y);

//using +-
printf("---------using(+-)----------\n");
x=x+y;
y=x-y;
x=x-y;
printf("x = %d , y=%d\n",x,y);

//using ^
printf("----------using(^)---------\n");
x=x^y;
y=x^y;
x=x^y;
printf("x = %d , y=%d\n",x,y);

return 0;
}