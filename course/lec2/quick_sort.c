#include<stdio.h>
#include<stdlib.h>

int find_partition_point(int *arr,int lb,int ub)
{
int pivot = lb;
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && arr[e]<=arr[pivot]) ++e;
while(f>lb && arr[f]>arr[pivot]) --f;
if(e<f)
{
g=arr[e];
arr[e]=arr[f];
arr[f]=g;
}
else
{
g=arr[f];
arr[f]=arr[pivot];
arr[pivot]=g;
}
}
return f;
}

/*
void _quick_sort(int *arr,int lb,int ub)
{
if(lb<ub)
{
int pp=find_partition_point(arr,lb,ub);
_quick_sort(arr,lb,pp-1);
_quick_sort(arr,pp+1,ub);
}
}
*/

void quick_sort(int *arr,int sz)
{
int stack[20][2];
int top=20;
int lb,ub,pp;
//insert on stack
top--;
stack[top][0]=0;
stack[top][1]=sz-1;
while(top!=20)
{
lb=stack[top][0];
ub=stack[top][1];
++top;
pp=find_partition_point(arr,lb,ub);
if(lb<pp-1)
{
top--;
stack[top][0]=lb;
stack[top][1]=pp-1;
}
if(pp+1<ub)
{
top--;
stack[top][0]=pp+1;
stack[top][1]=ub;
} //if ends here
} //while ends here
}

int main()
{
int req;
int *collection;
printf("Enter How many Numbers : ");
scanf("%d",&req);

if(req<=0)
{
printf("Invalid Requirement");
return 0;
}

collection=(int *)malloc(sizeof(int)*req);
if(collection==NULL)
{
printf("Not Enough Memory\n");
return 1;
}

for(int i=0;i<req;++i)
{
scanf("%d",&collection[i]);
}


//sorting logic
quick_sort(collection,req);
//ends here


for(int i=0;i<req;++i)
{
printf("%d ",collection[i]);
}

free(collection);

return 0;
}