#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>
#include<mg_stack.h>
#include<mg_queue.h>
#include<mg_heap.h>

typedef struct _Node
{
unsigned char ch;
int freq,depth;
struct _Node *left,*right,*parent;
}Node;
typedef struct _BSTNode
{
unsigned char ch;
int freq;
Node *location;
struct _BSTNode *left,*right;
}BSTNode;

Node * createNode(unsigned char ch,int freq)
{
Node *n=(Node *)malloc(sizeof(Node));
n->ch=ch;
n->freq=freq;
n->left=n->right=n->parent=NULL;
return n;
}
BSTNode * createBSTNode(unsigned char ch,int freq)
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

void addToBST(unsigned char ch)
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

void inorderTraversal(FILE *fw,BSTNode *root)
{
if(!root) return;
inorderTraversal(fw,root->left);
//process here
//write in file as char and freq
fwrite(&root->ch,sizeof(char),1,fw);
fwrite(&root->freq,sizeof(int),1,fw);
//processing ends here
inorderTraversal(fw,root->right);
}

int main(int argc,char *argv[])
{
long size;
int x;
int lengthOfNameOfFile,i,j;
int bit_index,byte_index,bit_count,byte_count,e,bit_number,g;
unsigned char *bytes;
char *fileName,*newFileName,*dot;
int ch;
BSTRoot=NULL;
root=NULL;
node_count=0;
Stack *stk;
FILE *f,*fw;
if(argc!=2)
{
printf("Usage : mgzipper somefile.txt");
return 0;
}
fileName=argv[1];
f=fopen(fileName,"rb");
if(f==NULL)
{
printf("File Does Not Exists\n");
return 0;
}
fseek(f,0,2);
size=ftell(f);
fseek(f,0,0);
if(size==0)
{
printf("File is Empty\n");
return 0;
}

//step1 : Create BST
//infinite loop to read char by char
while((e=fgetc(f))!=EOF)
{
addToBST((unsigned char)e);
}

//only 1 character or \0 at start 
if(node_count==0)
{
node_count++;
BSTRoot=createBSTNode('A',0);
}
if(node_count==1)
{
node_count++;
if(BSTRoot->ch=='A') //create B and add to right
{
BSTRoot->right=createBSTNode('B',0);
}
else
{
if(BSTRoot->ch<'A') BSTRoot->right=createBSTNode('A',0);
else BSTRoot->left=createBSTNode('A',0);
}
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
bit_count=totalBits;
byte_count=bit_count/8;
if(bit_count%8!=0) byte_count++;
bytes=calloc(byte_count,sizeof(unsigned char));

//open writer file
newFileName=(char *)malloc(strlen(fileName)+10);
strcpy(newFileName,fileName);
dot=strrchr(newFileName,'.');
if(dot!=NULL)
{
*dot='\0';
}
strcat(newFileName,".mgzip");

//open the writer file and Write Header
/*
EVERYTHING IN BINARY
---Structure of the Header---
length / number of bits (bit_count) ,
Unique Char Count (node_count) ,
for Each Char :
	char and freq
Then Sequence of Bytes
*/

fw=fopen(newFileName,"wb");
fwrite(&bit_count,sizeof(int),1,fw); 
fwrite(&node_count,sizeof(int),1,fw); 

//this function will traverse BST inorder and write header data in file
//char and freq
inorderTraversal(fw,BSTRoot);

//after Header write bytes

//step7 : Encode The Input String
fseek(f,0,0); //bring pointer to start
//infinite loop to read char by char
i=0;
j=0;
while(1)
{
ch=fgetc(f);
if(feof(f)) break;
//find this ch in BST
tmp=BSTRoot;
while(tmp)
{
if(tmp->ch==(unsigned char)ch) break;
if(tmp->ch>(unsigned char)ch) tmp=tmp->left;
else tmp=tmp->right;
}
u=tmp->location;
while(u)
{
m=u->parent;
if(m==NULL) break;
if(m->right==u)
{
pushOnStack(stk,(void *)(intptr_t)1,&succ);
}
else //append 0
{
pushOnStack(stk,(void *)(intptr_t)0,&succ);
}
u=u->parent;
} //while (u) loop to traverse from leaf to parent
while(!isStackEmpty(stk))
{
x=(int)(intptr_t)popFromStack(stk,&succ);
j<<=1;
if(x==1) j|=1;
i++;
if(i%8==0)
{
bytes[(i/8)-1]=j;
j=0;
}
} //while stack is not empty
} //while to read char from file
while(i%8!=0)
{
j<<=1;
i++;
}
if(bit_count%8)
{
bytes[(i/8)-1]=j;
}

fwrite(bytes,sizeof(char),byte_count,fw);

//cleanup
free(newFileName);
fclose(f);
fclose(fw);
destroyStack(stk);
destroyQueue(queue);
destroyHeap(heap);
destroyBST(BSTRoot);
destroyCBT(root);

return 0;
}