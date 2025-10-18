#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insertionSort(int *arr,int size)
{
if(size==1) return;
int y,z,num;
y=1;
while(y<size)
{
num=arr[y];
z=y-1;
while(z>=0 && arr[z]>num)
{
arr[z+1]=arr[z];
z--;
}
arr[z+1]=num;
y++;
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
insertionSort(arr,req);
printf("----------After Sorting----------\n");
show(arr,req);
free(arr);
return 0;
}