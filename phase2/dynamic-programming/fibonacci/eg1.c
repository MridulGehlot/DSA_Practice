#include<stdio.h>
int getNthFibonacciNumber(int n)
{
printf("Computing for %d Element\n",n);
if(n==0 || n==1) return n;
return getNthFibonacciNumber(n-1)+getNthFibonacciNumber(n-2);
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