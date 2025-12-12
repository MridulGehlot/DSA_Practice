#include<stdio.h>
#include<stdlib.h> //malloc,free
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
int hashValue(int num,int lg)
{
return num/lg;
}
void bucketSort(int *arr,int size)
{
int temp[10][10];
int sizes[10];
for(int i=0;i<10;i++) sizes[i]=0;
int largest=arr[0];
for(int i=0;i<size;i++)
{
if(arr[i]>largest) largest=arr[i];
}
int digits=1;
while(largest>0)
{
largest/=10;
digits*=10;
}
digits/=10;
int index;
for(int i=0;i<size;i++)
{
index=hashValue(arr[i],digits);
temp[index][sizes[index]]=arr[i];
sizes[index]++;
}
for(int i=0;i<size;i++) insertionSort(&temp[i][0],sizes[i]);
/*
for(int i=0;i<10;i++)
{
for(int j=0;j<10;j++) printf("%d ",temp[i][j]);
printf("\n");
}
*/
int num;
index=0;
for(int i=0;i<10;i++)
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
bucketSort(arr,req);
printf("----------After Sorting----------\n");
print(arr,req);
free(arr);
return 0;
}