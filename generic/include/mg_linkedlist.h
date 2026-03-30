#ifndef __mg_linkedlist
#define __mg_linkedlist

//nodes
typedef struct __SinglyLinkedListNode
{
void *ptr;
struct __SinglyLinkedListNode *next;
}SinglyLinkedListNode;

//Lists
typedef struct __SinglyLinkedList
{
int size;
SinglyLinkedListNode *start,*end;
}SinglyLinkedList;

//creating lists
SinglyLinkedList * createSinglyLinkedList(int *succ);

//adding data
void addToList(SinglyLinkedList *list,void *data,int *succ);
void insertAtTopOfList(SinglyLinkedList *list,void *data,int *succ);
void insertAt(int idx,SinglyLinkedList *list,void *data,int *succ);

//getting data
void * removeFromList(SinglyLinkedList *list,int *succ);

//Clearing Lists
void destroyList(SinglyLinkedList *list);

//getting size
int isListEmpty(SinglyLinkedList *list);
int getSizeOfList(SinglyLinkedList *list);

//Abandoned
/*
typedef struct __DoublyLinkedListNode
{
void *ptr;
struct __DoublyLinkedListNode *next,*prev;
}DoublyLinkedListNode;
typedef struct __DoublyLinkedList
{
int size;
DoublyLinkedListNode *start,*end;
}DoublyLinkedList;
DoublyLinkedList * createDoublyLinkedList(int *succ);
void addToList(DoublyLinkedList *list,void *data,int *succ);
void insertAtTopOfList(DoublyLinkedList *list,void *data,int *succ);
void insertAt(int idx,DoublyLinkedList *list,void *data,int *succ);
void * removeFromList(DoublyLinkedList *list,int *succ);
void destroyList(DoublyLinkedList *list,int *succ);
int isListEmpty(DoublyLinkedList *list);
int getSizeOfList(DoublyLinkedList *list);
*/

#endif