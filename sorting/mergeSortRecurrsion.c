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
void mergeSort(int *arr,int lb,int ub)
{
if(lb<ub)
{
int mid=(lb+ub)/2;
mergeSort(arr,lb,mid);
mergeSort(arr,mid+1,ub);
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
mergeSort(arr,0,req-1);
printf("----------After Sorting----------\n");
show(arr,req);
free(arr);
return 0;
}