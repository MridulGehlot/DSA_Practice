#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node *next,*prev,*down;
}Node;

Node *head=NULL;
Node *tail=NULL;

Node * createNode(int data)
{
Node *n=(Node *)malloc(sizeof(Node));
n->data=data;
n->prev=n->next=n->down=NULL;
return n;
}
void freeAll(Node *top)
{
Node *t;
while(top!=NULL)
{
t=top;
top=top->next;
free(t);
}
}
void createMultilevelDoublyLinkedList(int arr[],int start,int size,Node *top)
{
if(size<=0 || start>=size) return;
if(arr[0]==0) return;
Node *n,*t;
int i;
t=createNode(arr[start]);
if(head==NULL)
{
head=tail=t;
}
else
{
top->down=t;
tail=t;
}
for(i=start+1;i<size;i++)
{
if(arr[i]==0) break;
n=createNode(arr[i]);
n->prev=tail;
tail->next=n;
tail=n;
}
if(top) n=top->down;
else n=head;
i++;
while(i<size && arr[i]==0)
{
n=n->next;
i++;
}
if(i<size) createMultilevelDoublyLinkedList(arr,i,size,n);
}
void traverse(Node *head)
{
for(Node *t=head;t!=NULL;t=t->next)
{
printf("%d ",t->data);
//if(t->down) traverse(t->down);
}
}
Node * flattenList(Node *head)
{
if(!head) return head;
Node *n,*t,*u;
n=head;
while(n!=NULL && n->down==NULL)
{
t=n;
n=n->next;
}
if(n==NULL) return t;
u=n->next;
t=flattenList(n->down);
n->next=n->down;
n->down->prev=n;
n->down=NULL;
t->next=u;
if(u) u->prev=t;
while(u)
{
t=u;
u=u->next;
}
return t;
}
int main()
{
int arr[19]={10,50,5,70,62,93,84,0,0,0,70,50,0,0,67,84,59,0,32};
createMultilevelDoublyLinkedList(arr,0,19,NULL);
flattenList(head);
traverse(head);
freeAll(head);
return 0;
}