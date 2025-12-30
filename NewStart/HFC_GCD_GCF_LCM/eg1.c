#include<stdio.h>
int main()
{
int x,y,g,rem;
printf("Enter a number - ");
scanf("%d",&x);
printf("Enter another number - ");
scanf("%d",&y);

//we will keep x greater and y smaller at start
if(y>x)
{
g=x;
x=y;
y=g;
}

//with loop
while(y!=0)
{
rem=x%y;
x=y;
y=rem;
}

printf("GCD of is %d",x);
return 0;
}