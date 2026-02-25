#include<stdio.h>
#include<iostream>
#include<queue>
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
void levelOrder(BSTNode *root)
{
if(!root) return;
queue<pair<BSTNode *,int>> qq;
BSTNode *t;
int curr=0;
qq.push({root,curr});
while(!qq.empty())
{
pair<BSTNode *,int> &x=qq.front();
qq.pop();
t=x.first;
printf("%d(%d) ",t->data,x.second);
if(t->left) qq.push({t->left,x.second+1});
if(t->right) qq.push({t->right,x.second+1});
}
}
int main()
{
insert(100);
insert(50);
insert(200);
insert(25);
insert(75);
insert(150);
insert(250);
insert(4);
insert(35);
insert(85);
insert(300);
printf("Level Order Traversal\n");
levelOrder(root);
return 0;
}