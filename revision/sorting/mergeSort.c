#include<stdio.h>
#include<stdlib.h>

void merge(int *arr,int lb,int mid,int ub)
{
int e,f,k,sz;
sz=ub-lb+1;
e=lb;
f=mid+1;
int tmp[sz];
k=0;
while(e<=mid && f<=ub)
{
if(arr[e]<arr[f]) tmp[k++]=arr[e++];
else tmp[k++]=arr[f++];
}
while(e<=mid) tmp[k++]=arr[e++];
while(f<=ub) tmp[k++]=arr[f++];
k=0;
e=lb;
while(k<sz) arr[e++]=tmp[k++];
}

void mergeSort(int *arr,int lb,int ub)
{
if(lb<ub)
{
int mid=(lb+ub)/2;
mergeSort(arr,lb,mid);
mergeSort(arr,mid+1,ub);
merge(arr,lb,mid,ub);
}
}

void Sort(int *arr,int size)
{
mergeSort(arr,0,size-1);
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