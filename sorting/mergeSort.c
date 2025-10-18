#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void show(int *arr,int size)
{
for(int i=0;i<size;i++) printf("%d\n",arr[i]);
}
void merge(int *arr,int lb1,int ub1,int lb2,int ub2)
{
int i,j,k,size;
size=(ub1-lb1)+(ub2-lb2)+2;
int tmp[size];
i=lb1;
j=lb2;
k=0;
while(i<=ub1 && j<=ub2)
{
if(arr[i]<arr[j])
{
tmp[k]=arr[i];
i++;
}
else
{
tmp[k]=arr[j];
j++;
}
k++;
}
while(i<=ub1)
{
tmp[k]=arr[i];
k++;
i++;
}
while(j<=ub2)
{
tmp[k]=arr[j];
k++;
j++;
}
k=0;
i=lb1;
while(i<=ub1)
{
arr[i++]=tmp[k++];
}
i=lb2;
while(i<=ub2)
{
arr[i++]=tmp[k++];
}
}
void mergeSort(int *arr,int size)
{
int lb,ub,top1,top2,a,b,mid;
int stack1[10][2];
int stack2[10][2];
top1=10;
top2=10;
lb=0;
ub=size-1;
//push on stack1;
top1--;
stack1[top1][0]=lb;
stack1[top1][1]=ub;
while(top1!=10)
{
a=stack1[top1][0];
b=stack1[top1][1];
top1++;
top2--;
stack2[top2][0]=a;
stack2[top2][1]=b;
mid=(a+b)/2;
if(a<mid)
{
top1--;
stack1[top1][0]=a;
stack1[top1][1]=mid;
}
if(mid+1<b)
{
top1--;
stack1[top1][0]=mid+1;
stack1[top1][1]=b;
}
}
while(top2!=10)
{
lb=stack2[top2][0];
ub=stack2[top2][1];
top2++;
mid=(lb+ub)/2;
merge(arr,lb,mid,mid+1,ub);
}
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
mergeSort(arr,req);
printf("----------After Sorting----------\n");
show(arr,req);
free(arr);
return 0;
}