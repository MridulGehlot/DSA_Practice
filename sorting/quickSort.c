#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void quickSort(int *arr,int size)
{
int stack[10][2];
int top,lb,ub,e,f,pp,tmp;
lb=0;
ub=size-1;
top=10;
//push lb,ub on stack
top--;
stack[top][0]=lb;
stack[top][1]=ub;
while(top!=10)
{
//pop
lb=stack[top][0];
ub=stack[top][1];
top++;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && arr[e]<=arr[lb]) e++;
while(arr[f]>arr[lb]) f--;
if(e<f)
{
tmp=arr[e];
arr[e]=arr[f];
arr[f]=tmp;
}
else
{
tmp=arr[f];
arr[f]=arr[lb];
arr[lb]=tmp;
pp=f;
}
}
if(pp+1<ub)
{
top--;
stack[top][0]=pp+1;
stack[top][1]=ub;
}
if(lb<pp-1)
{
top--;
stack[top][0]=lb;
stack[top][1]=pp-1;
}
}
}
void show(int *arr,int size)
{
for(int i=0;i<size;i++) printf("%d\n",arr[i]);
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
quickSort(arr,req);
printf("----------After Sorting----------\n");
show(arr,req);
free(arr);
return 0;
}