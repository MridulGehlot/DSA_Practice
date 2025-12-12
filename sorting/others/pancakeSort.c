#include<stdio.h>
#include<stdlib.h> //malloc,free
void reverse(int *arr,int lb,int ub)
{
int tmp;
while(lb<ub)
{
tmp=arr[lb];
arr[lb]=arr[ub];
arr[ub]=tmp;
lb++;
ub--;
}
}
void pancakeSort(int *arr,int size)
{
int largest,index;
while(size>=0)
{
index=0;
largest=arr[0];
for(int i=1;i<size;i++)
{
if(arr[i]>largest)
{
largest=arr[i];
index=i;
}
}
reverse(arr,0,index);
reverse(arr,0,size-1);
size--;
}
}
void print(int *arr,int size)
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
pancakeSort(arr,req);
printf("----------After Sorting----------\n");
print(arr,req);
free(arr);
return 0;
}