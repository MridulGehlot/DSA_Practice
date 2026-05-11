#include<stdio.h>
#include<stdlib.h>
//for memo(r)ization | memoization we will maintain a DS (memo table)
typedef struct
{
int data;
char is_filled;
}memo;

memo *memoDS=NULL;

int getNthFibonacciNumber(int n)
{
memo *ptr=&memoDS[n];
if(ptr->is_filled=='Y') return ptr->data;
printf("Computing for %d Element\n",n);
if(n==0 || n==1) 
{
ptr->data=n;
ptr->is_filled='Y';
return n;
}
ptr->data=getNthFibonacciNumber(n-1)+getNthFibonacciNumber(n-2);
ptr->is_filled='Y';
return ptr->data;
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
memoDS=(memo *)calloc(n+1,sizeof(memo)); //is_filled will be 0
number=getNthFibonacciNumber(n);
printf("Element Number %d of Fibonacci Series is %d\n",n,number);
free(memoDS);
return 0;
}