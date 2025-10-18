#include<stdio.h>
#include<stdlib.h> //malloc,free
#include<string.h> //memcpy
void countingSort(int *arr,int size)
{
int *temp;
int largest,k;
largest=-1;
for(int i=0;i<size;i++) if(arr[i]>largest) largest=arr[i];
temp=(int *)malloc(sizeof(int)*(largest+1));
for(int i=0;i<largest+1;i++) temp[i]=0;
for(int i=0;i<size;i++)
{
temp[arr[i]]++;
}
k=0;
for(int i=0;i<largest+1;i++)
{
while(temp[i]>0)
{
temp[i]--;
arr[k++]=i;
}
}
free(temp);
}
void show(int *arr,int size)
{
int i=0;
while(i<size)
{
printf("%d\n",arr[i]);
i++;
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
countingSort(arr,req);
printf("----------After Sorting----------\n");
show(arr,req);
free(arr);
return 0;
}