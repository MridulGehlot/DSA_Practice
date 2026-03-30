#include<mg_linkedlist.h>
#include<stdlib.h>
#include<mg_error.h>

//creating lists
SinglyLinkedList * createSinglyLinkedList(int *succ)
{
*succ=FAILURE;
SinglyLinkedList *list=(SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
if(list==NULL)
{
*succ=MEM_ALLOC_ERROR;
return NULL;
}
list->size=0;
list->start=list->end=NULL;
*succ=SUCCESS;
return list;
}

//adding data
void addToList(SinglyLinkedList *list,void *data,int *succ)
{
*succ=FAILURE;
if(list==NULL)
{
*succ=NULL_VALUE;
return;
}
SinglyLinkedListNode *node=(SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
if(node==NULL)
{
*succ=MEM_ALLOC_ERROR;
return;
}
node->ptr=data;
node->next=NULL;
if(list->start==NULL)
{
list->start=list->end=node;
}
else
{
list->end->next=node;
list->end=node;
}
list->size++;
*succ=SUCCESS;
}
void insertAtTopOfList(SinglyLinkedList *list,void *data,int *succ)
{
*succ=FAILURE;
if(list==NULL)
{
*succ=NULL_VALUE;
return;
}
SinglyLinkedListNode *node=(SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
if(node==NULL)
{
*succ=MEM_ALLOC_ERROR;
return;
}
node->ptr=data;
node->next=NULL;
if(list->start==NULL)
{
list->start=list->end=node;
}
else
{
node->next=list->start;
list->start=node;
}
list->size++;
*succ=SUCCESS;
}
void insertAt(int idx,SinglyLinkedList *list,void *data,int *succ)
{
//yet to implement
}

//getting data
void * removeFromList(SinglyLinkedList *list,int *succ)
{
*succ=FAILURE;
if(list==NULL)
{
*succ=NULL_VALUE;
return NULL;
}
if(list->size==0)
{
*succ=EMPTY;
return NULL;
}
SinglyLinkedListNode *node=list->start;
list->start=list->start->next;
list->size--;
void *data=node->ptr;
free(node);
*succ=SUCCESS;
return data;
}

//Clearing Lists
void destroyList(SinglyLinkedList *list)
{
if(list==NULL) return;
SinglyLinkedListNode *node;
while(list->start!=NULL)
{
node=list->start;
list->start=list->start->next;
free(node->ptr);
free(node);
}
free(list);
}

//getting size
int isListEmpty(SinglyLinkedList *list)
{
if(list==NULL) return 1;
return list->size==0;
}
int getSizeOfList(SinglyLinkedList *list)
{
if(list==NULL) return 0;
return list->size;
}
