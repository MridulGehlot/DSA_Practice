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
printf("Queue is Empty...\n");
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
void radixSort(int *arr,int size)
{
int idx,largest,count,tmp,base,mod,k,num;
Queue queue[10];
for(int i=0;i<10;i++) initQueue(&queue[i]);
//find Largest Number
largest=-1;
for(int i=0;i<size;i++)
{
if(abs(arr[i])>largest) largest=arr[i];
}
tmp=largest;
count=0;
while(tmp)
{
tmp=tmp/10;
count++;
}
base=1;
mod=10;
while(count--)
{
for(int i=0;i<size;i++)
{
num=arr[i];
tmp=abs(num);
tmp=tmp/base;
idx=tmp%mod;
push(&queue[idx],num);
}
//Collect Back
k=0;
for(int j=0;j<10;j++)
{
while(!isEmpty(&queue[j]))
{
arr[k++]=pop(&queue[j]);
}
}
base=base*10;
}
/*
//extra processing
printf("\n-----Extra------\n");
for(int i=0;i<size;i++) printf("%d ",arr[i]);
printf("\n-----Extra------\n");
*/
k=0;
idx=size-1;
while(k<idx)
{
while(arr[idx]>0) idx--;
if(k<idx)
{
//printf("k - %d,idx - %d\n",k,idx);
num=arr[k];
arr[k++]=arr[idx];
//for(int i=0;i<size;i++) printf("%d ",arr[i]);
//printf("\n******\n");
for(int i=idx;i>=k;i--) arr[i]=arr[i-1];
//printf("\n******\n");
//for(int i=0;i<size;i++) printf("%d ",arr[i]);
arr[k]=num;
//printf("\n******\n");
//for(int i=0;i<size;i++) printf("%d ",arr[i]);
}
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
radixSort(arr,req);
printf("----------After Sorting----------\n");
show(arr,req);
free(arr);
return 0;
}