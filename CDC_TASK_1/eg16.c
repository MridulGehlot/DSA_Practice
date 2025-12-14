#include<stdio.h>
int gcd(int a,int b)
{
if(b==0) return a;
return gcd(b,a%b);
}
int main()
{
int x,y,z;
printf("Enter a Number : ");
scanf("%d",&x);
printf("Enter another Number : ");
scanf("%d",&y);
z=gcd(x,y);
printf("GCD = %d",z);
return 0;
}