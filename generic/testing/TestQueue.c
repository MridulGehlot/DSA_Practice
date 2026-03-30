#include<stdio.h>
#include<mg_queue.h>
#include<stdlib.h>
int main()
{
Queue *queue;
int succ;
int *x;
queue=createQueue(&succ);
for(int i=101;i<=110;i++)
{
x=(int *)malloc(sizeof(int));
*x=i;
addToQueue(queue,(void *)x,&succ);
}
while(!isQueueEmpty(queue))
{
x=(int *)removeFromQueue(queue,&succ);
printf("%d ",*x);
free(x);
}
return 0;
}