#include<stdio.h>
#include<stdlib.h> //malloc,free
void pigeonHoleSort(int *arr,int size)
{
int smallest,largest,range;
smallest=largest=arr[0];
for(int i=1;i<size;i++)
{
if(arr[i]>largest) largest=arr[i];
if(arr[i]<smallest) smallest=arr[i];
}
range=largest-smallest+1;
int temp[range][10];
int sizes[range];
for(int i=0;i<range;i++) sizes[i]=0;
int num,index;
for(int i=0;i<size;i++)
{
num=arr[i];
index=num-smallest;
temp[index][sizes[index]++]=num;
}
//collect back
index=0;
for(int i=0;i<range;i++)
{
for(int j=0;j<sizes[i];j++)
{
num=temp[i][j];
arr[index++]=num;
}
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
pigeonHoleSort(arr,req);
printf("----------After Sorting----------\n");
print(arr,req);
free(arr);
return 0;
}