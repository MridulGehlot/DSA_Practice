#include<stdio.h>
#include<stdlib.h>

void merge(int *arr,int lb1,int ub1,int lb2,int ub2)
{
int i,j,k,size;
size= (ub2-lb2+1) + (ub1-lb1+1);
int tmp[size];
k=0;
i=lb1;
j=lb2;
while(i<=ub1 && j<=ub2)
{
if(arr[i]<arr[j])
{
tmp[k]=arr[i++];
}
else tmp[k]=arr[j++];
++k;
}
while(i<=ub1)
{
tmp[k]=arr[i++];
++k;
}
while(j<=ub2)
{
tmp[k]=arr[j++];
++k;
}
//copy back
k=0;
i=lb1;
while(k<size)
{
arr[i++]=tmp[k++];
}
}

void merge_sort(int *arr,int sz)
{
int top1,top2,a,b,mid;
int stack1[10][2];
int stack2[10][2];
top1=top2=10;

//push on stack1 0 and sz-1
--top1;
stack1[top1][0]=0;
stack1[top1][1]=sz-1;
while(top1!=10)
{
//pop from stack1
a=stack1[top1][0];
b=stack1[top1][1];
++top1;
//push on stack 2
--top2;
stack2[top2][0]=a;
stack2[top2][1]=b;
mid=(a+b)/2;
//push on stack1
if(a<mid)
{
--top1;
stack1[top1][0]=a;
stack1[top1][1]=mid;
}
if(mid+1<b)
{
--top1;
stack1[top1][0]=mid+1;
stack1[top1][1]=b;
}
}

while(top2!=10)
{
a=stack2[top2][0];
b=stack2[top2][1];
++top2;
mid=(a+b)/2;
merge(arr,a,mid,mid+1,b);
}

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
merge_sort(collection,req);
//ends here


for(int i=0;i<req;++i)
{
printf("%d ",collection[i]);
}

free(collection);

return 0;
}