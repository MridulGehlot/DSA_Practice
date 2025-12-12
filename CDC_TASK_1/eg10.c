#include<stdio.h>
int main()
{
int arr[5]={12,45,23,65,88};
printf("ORIGNIAL Array\n");
for(int i=0;i<5;i++) printf("%d ",arr[i]);
int x,y,temp;
x=0;
y=5-1;
while(x<y)
{
temp=arr[x];
arr[x]=arr[y];
arr[y]=temp;
x++;
y--;
}
printf("\nREVERSED Array\n");
for(int i=0;i<5;i++) printf("%d ",arr[i]);
return 0;
}