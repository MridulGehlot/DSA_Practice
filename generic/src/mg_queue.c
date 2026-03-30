#include<mg_queue.h>
#include<mg_linkedlist.h>
#include<mg_error.h>
#include<stdlib.h>

Queue * createQueue(int *succ)
{
*succ=FAILURE;
Queue *queue=(Queue *)malloc(sizeof(Queue));
if(queue==NULL)
{
*succ=MEM_ALLOC_ERROR;
return NULL;
}
int x;
queue->list=createSinglyLinkedList(&x);
if(x==FAILURE || x==MEM_ALLOC_ERROR || queue->list==NULL)
{
return NULL;
}
return queue;
}

void addToQueue(Queue *queue,void *data,int *succ)
{
addToList(queue->list,data,succ);
}
void * removeFromQueue(Queue *queue,int *succ)
{
return removeFromList(queue->list,succ);
}
void * elementAtFrontOfQueue(Queue *queue,int *succ)
{
return queue->list->start->ptr;
}

int getSizeOfQueue(Queue *queue)
{
if(queue==NULL) return 0;
return getSizeOfList(queue->list);
}
int isQueueEmpty(Queue *queue)
{
if(queue==NULL) return 1;
return isListEmpty(queue->list);
}

void destroyQueue(Queue *queue)
{
if(queue==NULL || queue->list==NULL) return;
destroyList(queue->list);
free(queue);
}