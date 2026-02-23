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
void preorder(BSTNode *root)
{
stack<BSTNode*> stk;
BSTNode *t;
t=root;
stk.push(t);
while(!stk.empty())
{
t=stk.top();
stk.pop();
printf("%d ",t->data);
if(t->right) stk.push(t->right);
if(t->left) stk.push(t->left);
}
}
int main()
{
insert(100);
insert(50);
insert(175);
insert(75);
insert(200);
insert(10);
insert(45);
insert(170);
insert(80);
insert(20);
printf("Printing Pre Order Traversal Iterative\n");
preorder(root);
return 0;
}