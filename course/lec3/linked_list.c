#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
int data;
struct _node *next;
}Node;

Node *top,*bottom;

Node * createNode(int data)
{
Node *n=(Node *)malloc(sizeof(Node));
n->data=data;
n->next=NULL;
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
}

int main()
{
top=NULL;
bottom=NULL;
int ch,x,y,z;
do
{
printf("-----MENU-----\n");
printf("1. Add Element At Top\n");
printf("2. Add Element At Bottom\n");
printf("3. Add Element At Index\n");
printf("4. Print All Elements\n");
printf("5. Exit\n");
printf("Enter Your Choice : ");
scanf("%d",&ch);

if(ch==1) 
{
printf("Enter Number : ");
scanf("%d",&x);
addToTop(x);
}
else if(ch==2)
{
printf("Enter Number : ");
scanf("%d",&x);
addToBottom(x);
}
else if(ch==3)
{
printf("Enter Number : ");
scanf("%d",&x);
printf("Enter Index : ");
scanf("%d",&y);
addToIndex(x,y);
}
else if(ch==4) print_all();
}while(ch!=5);

destroy_all_nodes();
return 0;
}