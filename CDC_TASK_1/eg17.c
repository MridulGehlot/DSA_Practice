#include<stdio.h>
int gcd(int a,int b)
{
if(b==0) return a;
return gcd(b,a%b);
}
int lcm(int a,int b)
{
/*
int prod=a*b;
int g=gcd(a,b);
return prod/g;
*/
int g=gcd(a,b);
return (a/g)*b;
}
int main()
{
int x,y,z;
printf("Enter a Number : ");
scanf("%d",&x);
printf("Enter another Number : ");
scanf("%d",&y);
z=lcm(x,y);
printf("LCM = %d",z);
return 0;
}