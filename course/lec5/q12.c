/*
create Multilevel DLL from array where 0 has special meaning
For Now Consider its always valid not invalid 0 counts
Task -> To Flatten the array 
int arr[19]={10,50,5,70,62,93,84,0,0,0,70,50,0,0,67,84,59,0,32};

output -> 10 50 5 70 50 67 32 84 59 70 62 93 84
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
int data;
struct _node *prev,*next,*down;
}node;

node * createNode(int data)
{
node *n=(node *)malloc(sizeof(node));
n->data=data;
n->next=n->prev=n->down=NULL;
return n;
}

node * root;

void traverse(node *r)
{
if(!root) return;
for(node *n=r;n!=NULL;n=n->next)
{
printf("%d ",n->data);
if(n->down)
{
 traverse(n->down);
}
}
}

int main()
{
int arr[19]={10,50,5,70,62,93,84,0,0,0,70,50,0,0,67,84,59,0,32};
node *n,*head,*p,*temp;
head=NULL;
root=NULL;
for(int i=0;i<19;++i)
{
if(arr[i]==0)
{
++i;
temp=head;
printf("start temp data = %d\n",temp->data);
while(arr[i]==0)
{
printf("temp data = %d\n",temp->data);
temp=temp->next;
++i;
}
printf("end temp data = %d\n",temp->data);
n=createNode(arr[i]);
temp->down=n;
head=p=n;
}
else 
{
n=createNode(arr[i]);
if(root==NULL) root=n;
if(head==NULL) 
{
head=n;
p=n;
}
else
{
p->next=n;
n->prev=p;
p=n; //important
}
}
printf("Created Node %d\n",n->data);
}

traverse(root);

return 0;
}