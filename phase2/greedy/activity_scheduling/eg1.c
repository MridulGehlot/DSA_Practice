#include<stdio.h>
int main()
{
int i,j,size,idx,lastEndTime;
struct activity
{
int start,end;
};
struct activity arr[6]={
{1,2},
{1,6},
{3,4},
{5,6},
{8,9},
{7,9}
};
size=6;
struct activity tmp;
//sort them by end time
for(i=0;i<size-1;i++)
{
for(j=i+1;j<size;j++)
{
if(arr[j].end<arr[i].end)
{
tmp=arr[j];
arr[j]=arr[i];
arr[i]=tmp;
}
}
}
//for testing print them
printf("Start  -  End\n");
for(i=0;i<size;i++) printf("%d  -  %d\n",arr[i].start,arr[i].end);
int schedule[size];
idx=0;
lastEndTime=arr[0].end;
schedule[idx]=0;
idx++;
for(i=1;i<size;i++)
{
if(arr[i].start>=lastEndTime)
{
schedule[idx++]=i;
lastEndTime=arr[i].end;
}
}
//print result
printf("Schedule is as Follows\n");
printf("Start  -  End\n");
for(i=0;i<idx;i++)
{
j=schedule[i];
printf("%d  -  %d\n",arr[j].start,arr[j].end);
}
return 0;
}