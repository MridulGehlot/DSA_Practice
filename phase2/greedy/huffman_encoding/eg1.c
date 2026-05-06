#include<stdio.h>
#include<stdlib.h>
#include<mg_stack.h>
#include<mg_queue.h>
#include<mg_heap.h>

typedef struct _Node
{
char ch;
int freq,depth;
struct _Node *left,*right,*parent;
}Node;
typedef struct _BSTNode
{
char ch;
int freq;
Node *location;
struct _BSTNode *left,*right;
}BSTNode;

Node * createNode(char ch,int freq)
{
Node *n=(Node *)malloc(sizeof(Node));
n->ch=ch;
n->freq=freq;
n->left=n->right=n->parent=NULL;
return n;
}
BSTNode * createBSTNode(char ch,int freq)
{
BSTNode *n=(BSTNode *)malloc(sizeof(BSTNode));
n->ch=ch;
n->freq=freq;
n->location=NULL;
n->left=n->right=NULL;
return n;
}

BSTNode * BSTRoot;
Node * root;
int node_count;

void addToBST(char ch)
{
BSTNode *t,*u;
u=BSTRoot;
t=NULL;
while(u)
{
t=u;
if(u->ch==ch) break;
if(u->ch>ch) u=u->left;
else u=u->right;
}
if(u==NULL) //not found
{
node_count++;
u=createBSTNode(ch,1);
if(BSTRoot==NULL) BSTRoot=u;
else
{
if(ch>t->ch) t->right=u;
else t->left=u;
}
}
else //found
{
u->freq++;
}
}

int cmp(void *a,void *b)
{
Node *x=(Node *)a;
Node *y=(Node *)b;
return x->freq<y->freq;
}

void destroyBST(BSTNode *r)
{
if(!r) return;
destroyBST(r->left);
destroyBST(r->right);
free(r);
}
void destroyCBT(Node *r)
{
if(!r) return;
destroyCBT(r->left);
destroyCBT(r->right);
free(r);
}

int main()
{
char str[11]="bcaabcddba\0";
char ch;
BSTRoot=NULL;
root=NULL;
node_count=0;
Stack *stk;
//step1 : Create BST
for(int i=0;str[i]!='\0';i++)
{
addToBST(str[i]);
}
//step2 : Create Min Heap
int succ;
Heap *heap;
Queue *queue;
Node *n,*u,*m;
BSTNode *tmp;
//step3 : Traverse Preorder without recursion using stack and create heap
stk=createStack(&succ);
heap=createHeap(cmp,&succ);
queue=createQueue(&succ);
//traverse preorder (process & push)
tmp=BSTRoot;
while(tmp)
{
pushOnStack(stk,(void *)tmp,&succ);
n=createNode(tmp->ch,tmp->freq);
insert(heap,(void *)n,&succ);
tmp->location=n;
tmp=tmp->left;
}
while(!isStackEmpty(stk))
{
tmp=(BSTNode *)popFromStack(stk,&succ);
tmp=tmp->right;
while(tmp)
{
pushOnStack(stk,(void *)tmp,&succ);
n=createNode(tmp->ch,tmp->freq);
insert(heap,(void *)n,&succ);
tmp->location=n;
tmp=tmp->left;
}
}
//step4 : Create Huffman Code Tree pop 2 and merge
while(getSizeOfHeap(heap)>1)
{
n=(Node *)removeFromHeap(heap,&succ);
u=(Node *)removeFromHeap(heap,&succ);
m=createNode('\0',n->freq+u->freq);
m->left=n;
m->right=u;
n->parent=u->parent=m;
insert(heap,(void *)m,&succ);
}
root=(Node *)removeFromHeap(heap,&succ);
//step5 : Traverse Level Order The Huffman Tree And Assign DEPTH
int depth,sz,totalBits;
depth=0;
totalBits=0;
addToQueue(queue,(void *)root,&succ);
while(!isQueueEmpty(queue))
{
sz=getSizeOfQueue(queue);
for(int i=0;i<sz;i++)
{
n=removeFromQueue(queue,&succ);
n->depth=depth;
if(n->left) addToQueue(queue,(void *)n->left,&succ);
if(n->right) addToQueue(queue,(void *)n->right,&succ);
if(n->left==NULL && n->right==NULL) //leaf Node
{
totalBits+=n->depth*n->freq;
}
}
depth++;
}
//step6 : Allocate Memory For Bit Count Characters
char *arr=(char *)malloc(sizeof(char)*(totalBits+1));
//step7 : Encode The Input String
int idx=totalBits;
arr[idx]='\0';
idx--;
for(int i=9;i>=0;i--)
{
ch=str[i];
//find ch in BST
tmp=BSTRoot;
while(tmp)
{
if(tmp->ch==ch) break;
if(tmp->ch>ch) tmp=tmp->left;
else tmp=tmp->right;
}
u=tmp->location;
while(u)
{
m=u->parent;
if(m==NULL) break;
if(m->right==u) arr[idx--]='1';
else arr[idx--]='0';
u=u->parent;
}
}
printf("Encoded String is : %s\n",arr);
//step9 : Decode The String
u=root;
for(int i=0;arr[i]!='\0';i++)
{
if(u->left==NULL && u->right==NULL) //leaf
{
printf("%c",u->ch);
u=root;
}
if(arr[i]=='1') u=u->right;
else u=u->left;
}
printf("%c",u->ch);
printf("\n%s (Original)",str);
//step10 : Cleanup task
destroyStack(stk);
destroyQueue(queue);
//destroyHeap(heap);
destroyBST(BSTRoot);
destroyCBT(root);
return 0;
}