#include<stdio.h>
void sam(int n)
{
if(n==0) return;
printf("%d\n",n);
sam(n-1);
}
int main()
{
sam(5);
return 0;
}