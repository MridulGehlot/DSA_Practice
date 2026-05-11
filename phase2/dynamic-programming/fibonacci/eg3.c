#include<stdio.h>
int getNthFibonacciNumber(int n)
{
if(n==1 || n==0) return n;
int e,f,g,i;
e=0;
f=1;
for(i=2;i<=n;i++)
{
g=e+f;
e=f;
f=g;
}
return g;
}
int main()
{
int n,number;
printf("You want which element of fibonacci series : ");
scanf("%d",&n);
if(n<0)
{
printf("Invalid Input\n");
return 0;
}
number=getNthFibonacciNumber(n);
printf("Element Number %d of Fibonacci Series is %d\n",n,number);
return 0;
}