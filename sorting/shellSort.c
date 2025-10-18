#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void shellSort(int *arr,int size)
{
int y,num,z,diff;
diff=size/2;
while(diff>0)
{
y=0+diff;
while(y<size)
{
num=arr[y];
z=y-diff;
while(z>=0 && arr[z]>num)
{
arr[z+diff]=arr[z];
z=z-diff;
}
arr[z+diff]=num;
y+=diff;
}
diff=diff/2;
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
shellSort(arr,req);
printf("----------After Sorting----------\n");
show(arr,req);
free(arr);
return 0;
}