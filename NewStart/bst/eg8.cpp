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
void postorder(BSTNode *root)
{
stack<BSTNode *> stk;
BSTNode *t;
t=root;
while(1)
{
while(t!=NULL)
{
if(t->right) stk.push(t->right);
stk.push(t);
t=t->left;
}
t=stk.top();
stk.pop();
if(!stk.empty() && t->right==stk.top())
{
stk.pop();
stk.push(t);
t=t->right;
}
else
{
printf("%d ",t->data);
t=NULL;
}
if(stk.empty()) break;
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
printf("Post Order Traversal Without Recurrsion\n");
postorder(root);
return 0;
}