#include<stdio.h>
int getSingleNumber(int *x,int sz)
{
int e,f;
for(e=0,f=0;f<sz;f++) e^=x[f];
return e;
}
int main()
{
int x[5]={1,2,3,1,2};
printf("%d",getSingleNumber(x,5));
return 0;
}