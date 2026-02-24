#include<stdio.h>
#include<iostream>
#include<stack>
#include<stdlib.h>
using namespace std;
typedef struct _BSTNode
{
int data;
struct _BSTNode *left,*right;
}BSTNode;
BSTNode *root=NULL;
BSTNode * createNode(int data)
{
BSTNode *n=(BSTNode *)malloc(sizeof(BSTNode));
n->data=data;
n->left=n->right=NULL;
return n;
}
void insert(int data)
{
BSTNode *n,*t;
n=createNode(data);
if(root==NULL)
{
root=n;
return;
}
t=root;
while(1)
{
if(t->data<data)
{
if(t->right) t=t->right;
else
{
t->right=n;
break;
}
}
else
{
if(t->left) t=t->left;
else
{
t->left=n;
break;
}
}
}
}
void inorder(BSTNode *root)
{
if(!root) return;
inorder(root->left);
printf("%d ",root->data);
inorder(root->right);
}
void deleteNode(int key)
{
BSTNode **p2p,*t,*j,*k,*m;
t=root;
while(t)
{
if(t->data==key) break;
j=t;
if(t->data>key) t=t->left;
else t=t->right;
}
if(!t) return;
if(t==root) p2p=&root;
else
{
if(j->left==t) p2p=&(j->left);
else p2p=&(j->right);
}
//deleting the node
m=k=NULL;
if(t->right) //successor
{
k=t->right;
while(k && k->left)
{
m=k;
k=k->left;
}
if(m) m->left=k->right;
if(k)
{
k->left=t->left;
if(m)k->right=t->right;
}
}
else //predessor
{
k=t->left;
while(k && k->right)
{
m=k;
k=k->right;
}
if(m) m->right=k->left;
if(k)
{
if(m) k->left=t->left;
k->right=t->right;
}
}
*p2p=k;
free(t);
}

int main()
{
insert(6);
insert(4);
insert(10);
insert(2);
insert(5);
insert(7);
insert(1);
insert(8);
printf("Deleting A Node\n");
deleteNode(10);
inorder(root);
return 0;
}