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
void delete(int val)
{
}
void inorder(BSTNode *root)
{
if(!root) return;
inorder(root->left);
printf("%d ",root->data);
inorder(root->right);
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
printf("Deleting A Node\n");
delete(50);
inorder(root);
return 0;
}