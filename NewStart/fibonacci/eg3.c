#include<stdio.h>
#include<stdlib.h>
int *arr;
int fibo(int n)
{
if(arr[n]==0)
{
if(n<=1) return 0;
else return arr[n]=fibo(n-1)+fibo(n-2);
}
else return arr[n];
}
int main()
{
int n;
printf("Enter n -> ");
scanf("%d",&n);
arr=(int *)calloc((n+1),sizeof(int));
if(arr==NULL)
{
printf("Unalbe to allocate memory loop solution\n");
return 0;
}
arr[0]=0;
arr[1]=0;
arr[2]=1;
int ans=fibo(n);
printf("nth fibonacci number is %d\n",ans);
free(arr);
return 0;
}