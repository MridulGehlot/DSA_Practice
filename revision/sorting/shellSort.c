#include<stdio.h>
#include<stdlib.h>

void Sort(int *arr,int size)
{
int z,y,num,diff;
diff=size/2;
while(diff>=1)
{
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
y+=diff;
}
diff/=2;
}
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