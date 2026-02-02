//Find missing numbers given numbers from 1 to n
#include<stdio.h>
void findMissingElement(int *x,int sz)
{
for(int i=0;i<sz;i++) if(x[i]>0) if(x[x[i]-1]>0) x[x[i]-1]=(-1)*x[x[i]-1];
}

int main()
{
int n=5;
int x[9]={2,3,3,3,4,2,3,3,3};
findMissingElement(x,9);
for(int i=0;i<n;i++)
{
if(x[i]>0) printf("%d ",i+1);
}
return 0;
}