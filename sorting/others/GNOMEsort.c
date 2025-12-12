#include<stdio.h>
#include<stdlib.h> //malloc,free
void GNOMESort(int *arr,int size)
{
int j=0;
int tmp;
while(j<size)
{
if(j==0) j++;
if(arr[j]<arr[j-1])
{
tmp=arr[j-1];
arr[j-1]=arr[j];
arr[j]=tmp;
j--;
}
else j++;
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
GNOMESort(arr,req);
printf("----------After Sorting----------\n");
print(arr,req);
free(arr);
return 0;
}