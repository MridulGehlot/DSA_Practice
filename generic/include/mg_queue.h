#ifndef __mg_queue
#define __mg_queue
#include "mg_linkedlist.h"
typedef struct __queue
{
SinglyLinkedList *list;
}Queue;

Queue * createQueue(int *succ);
void addToQueue(Queue *queue,void *data,int *succ);
void * removeFromQueue(Queue *queue,int *succ);
void * elementAtFrontOfQueue(Queue *queue,int *succ);
int getSizeOfQueue(Queue *queue);
int isQueueEmpty(Queue *queue);
void destroyQueue(Queue *queue);

#endif