#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
int data;
struct _node *next;
}Node;

Node *top,*bottom;
int nodes_count=0;

Node * createNode(int data)
{
Node *n=(Node *)malloc(sizeof(Node));
n->data=data;
n->next=NULL;
++nodes_count;
return n;
}

void addToTop(int data)
{
Node *n=createNode(data);
if(top==NULL) 
{
top=bottom=n;
}
else
{
n->next=top;
top=n;
}
}

void addToBottom(int data)
{
Node *n=createNode(data);
if(top==NULL)
{
top=bottom=n;
}
else
{
bottom->next=n;
bottom=n;
}
}

void addToIndex(int data,int index)
{
if(index<0) return;
int idx=0;
Node *n=createNode(data);
Node *t,*prev;
t=top;
prev=NULL;
while(idx<index && t)
{
prev=t;
t=t->next;
++idx;
}
if(t==NULL && idx!=index)
{
if(top==NULL)
{
top=bottom=n;
}
else 
{
bottom->next=n;
bottom=n;
}
}
//insert at 0 index
if(prev==NULL)
{
free(n);
addToTop(data);
}
prev->next=n;
n->next=t;
}


void removeFromTop()
{
if(top==NULL) return;
Node *n=top;
top=top->next;
free(n);
--nodes_count;
}

void removeFromBottom()
{
if(bottom==NULL) return;
Node *prev=top;
if(prev==bottom)
{
top=bottom=NULL;
free(prev);
return;
}
//at least 2 nodes
while(prev->next!=bottom) prev=prev->next;
prev->next=NULL;
free(bottom);
bottom=prev;
--nodes_count;
}

void removeFromIndex(int index)
{
if(index==0)
{
removeFromTop();
return;
}
if(index==nodes_count-1)
{
removeFromBottom();
return;
}

int idx=0;
Node *prev,*current;
current=top;
while(idx<index)
{
prev=current;
current=current->next;
++idx;
}

prev->next=current->next;
free(current);

--nodes_count;
}


void destroy_all_nodes()
{
Node *t,*prev;
t=top;
while(t)
{
prev=t;
t=t->next;
free(prev);
}
}


void print_all()
{
Node *t;
t=top;
while(t)
{
printf("%d ",t->data);
t=t->next;
}
printf("\n");
}


int main()
{
int stack[10];
int x;
int ch;
do
{
printf("-----MENU-----\n");
printf("1. Push\n");
printf("2. Pop\n");
printf("3. Print\n");
printf("4. Exit\n");
printf("Enter your Choice : ");
scanf("%d",&ch);

if(ch==1)
{
printf("Enter a Number : ");
scanf("%d",&x);
addToTop(x);
}
else if(ch==2)
{
if(nodes_count==0) printf("Stack is Empty, Cannot pop");
else
{
printf("Poped : %d",top->data);
removeFromTop();
}
}
else if(ch==3)
{
printf("Stack View From Top to bottom ");
print_all();
}
}while(ch!=4);

return 0;
}