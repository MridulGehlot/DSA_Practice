#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
int data;
struct node *next;
}Node;
typedef struct __queue
{
Node *start;
Node *end;
int size;
}Queue;
void initQueue(Queue *queue)
{
queue->start=NULL;
queue->end=NULL;
queue->size=0;
}
int isEmpty(Queue *queue)
{
return queue->size==0;
}
void push(Queue *queue,int data)
{
Node *tmp=(Node *)malloc(sizeof(Node));
tmp->data=data;
tmp->next=NULL;
if(queue->start==NULL)
{
queue->start=queue->end=tmp;
}
else
{
queue->end->next=tmp;
queue->end=tmp;
}
queue->size++;
}
int pop(Queue *queue)
{
if(queue->size==0)
{
printf("Stack is Empty...\n");
return -1;
}
int data;
Node *tmp=queue->start;
data=tmp->data;
queue->start=queue->start->next;
queue->size--;
free(tmp);
return data;
}

int main()
{
Queue queue;
initQueue(&queue);
push(&queue,10);
push(&queue,20);
push(&queue,30);
push(&queue,40);
push(&queue,50);
while(!isEmpty(&queue))
{
printf("%d\n",pop(&queue));
}
return 0;
}