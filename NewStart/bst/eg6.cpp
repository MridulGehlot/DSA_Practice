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
void countLeafNodes(BSTNode *root,int &count)
{
if(!root) return;
if(!root->left && !root->right)
{
count++;
return;
}
countLeafNodes(root->left,count);
countLeafNodes(root->right,count);
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
int count=0;
countLeafNodes(root,count);
printf("Number of Leaf Nodes are %d\n",count);
return 0;
}