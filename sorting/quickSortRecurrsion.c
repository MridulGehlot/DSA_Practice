#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int findPP(int *arr,int lb,int ub)
{
int e,f,num,tmp;
num=arr[lb];
e=lb;
f=ub;
while(e<f)
{
while(e<=ub && arr[e]<=num) e++;
while(arr[f]>num) f--;
if(e<f)
{
tmp=arr[f];
arr[f]=arr[e];
arr[e]=tmp;
}
else
{
arr[lb]=arr[f];
arr[f]=num;
}
}
return f;
}
void quickSort(int *arr,int lb,int ub)
{
if(lb<ub)
{
int pp=findPP(arr,lb,ub);
quickSort(arr,lb,pp-1);
quickSort(arr,pp+1,ub);
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
quickSort(arr,0,req-1);
printf("----------After Sorting----------\n");
show(arr,req);
free(arr);
return 0;
}