#include<stdio.h>
int main()
{
int x;
printf("Enter a Number : ");
scanf("%d",&x);
if(x%2) printf("Number is odd\n");
else printf("Number is even");
return 0;
}