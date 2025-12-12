#include<stdio.h>
int isPrime(int x)
{
if(x<=1) return 0;
for(int i=2;i*i<=x;i++)
{
if(x%i==0) return 0;
}
return 1;
}
int main()
{
int x,y;
printf("Enter a Number : ");
scanf("%d",&x);
if(isPrime(x)) printf("Number is prime number");
else printf("Number is not a prime number");
return 0;
}