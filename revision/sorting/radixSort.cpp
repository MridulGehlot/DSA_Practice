#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;
void Sort(int *arr,int size)
{
int maxi=arr[0];
for(int i=0;i<size;i++) if(arr[i]>maxi) maxi=arr[i];
queue<int> q[10];
int digits=0;
while(maxi)
{
digits++;
maxi/=10;
}
int base=1;
while(digits)
{
for(int i=0;i<size;i++)
{
int num=arr[i];
int idx=num/base;
idx%=10;
q[idx].push(num);
}
//re collect
int idx=0;
int k=0;
while(idx<=9)
{
while(!q[idx].empty())
{
arr[k++]=q[idx].front();
q[idx].pop();
}
idx++;
}
base*=10;
digits--;
}
}
void print(int *arr,int sz)
{
for(int i=0;i<sz;i++) printf("%d ",arr[i]);
}
int main()
{
int req;
int *arr;
printf("Enter Requirement - ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid Requirement");
return 0;
}
arr=(int *)malloc(sizeof(int)*req);
if(arr==NULL)
{
printf("Unable To Allocate Memory");
return 0;
}
for(int i=0;i<req;i++)
{
printf("Enter A Number - ");
scanf("%d",&arr[i]);
}
Sort(arr,req);
printf("----------After Sorting----------\n");
print(arr,req);
free(arr);
return 0;
}