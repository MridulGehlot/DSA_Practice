#include<stdio.h>
#include<stdlib.h>
int main()
{
int y,j,total,numberOfJobs,max_dead_line,slots_left;
int *slots;
struct job
{
int sno;
int gift_value;
int dead_line;
};

numberOfJobs=5;
struct job jobs[5];
struct job temp;

jobs[0].sno=1;
jobs[0].gift_value=150;
jobs[0].dead_line=2;
jobs[1].sno=2;
jobs[1].gift_value=20;
jobs[1].dead_line=1;
jobs[2].sno=3;
jobs[2].gift_value=25;
jobs[2].dead_line=2;
jobs[3].sno=4;
jobs[3].gift_value=30;
jobs[3].dead_line=1;
jobs[4].sno=5;
jobs[4].gift_value=29;
jobs[4].dead_line=2;

//applying insertion sort to sort by MAX GIFT Value
for(y=1;y<numberOfJobs;y++)
{
temp=jobs[y];
j=y-1;
while(j>=0)
{
if(jobs[j].gift_value<temp.gift_value)
{
jobs[j+1]=jobs[j];
}
else break;
j--;
}
jobs[j+1]=temp;
}

//for testing print values after sorting
printf("SNO  GIFT_VALUE   DEADLINE\n");
for(j=0;j<numberOfJobs;j++) printf("%d  %d   %d\n",jobs[j].sno,jobs[j].gift_value,jobs[j].dead_line);

//find maximum dead_line
max_dead_line=jobs[0].dead_line;
for(j=1;j<numberOfJobs;j++) if(jobs[j].dead_line>max_dead_line) max_dead_line=jobs[j].dead_line;

//create slots
slots=(int *)malloc(sizeof(int)*max_dead_line);
for(y=0;y<max_dead_line;y++) slots[y]=-1;

//schedule jobs
total=0;
slots_left=max_dead_line;
for(y=0;y<numberOfJobs && slots_left;y++)
{
j=jobs[y].dead_line-1;
while(j>=0)
{
if(slots[j]==-1)
{
total+=jobs[y].gift_value;
slots[j]=y;
slots_left--;
break;
}
j--;
}
}

//print Results
printf("Schedule is as Follows\n");
printf("SNO  GIFT_VALUE   DEADLINE\n");
for(y=0;y<max_dead_line;y++)
{
j=slots[y];
if(j==-1) continue;
printf("%d  %d   %d\n",jobs[j].sno,jobs[j].gift_value,jobs[j].dead_line);
}
printf("Total Profit = %d",total);

free(slots);

return 0;
}