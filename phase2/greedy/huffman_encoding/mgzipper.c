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

BSTNode *BSTRoot;
Node *root;
int node_count;

Node *createNode(unsigned char ch,int freq)
{
    Node *n=(Node *)malloc(sizeof(Node));
    n->ch=ch;
    n->freq=freq;
    n->left=n->right=n->parent=NULL;
    return n;
}

BSTNode *createBSTNode(unsigned char ch,int freq)
{
    BSTNode *n=(BSTNode *)malloc(sizeof(BSTNode));
    n->ch=ch;
    n->freq=freq;
    n->location=NULL;
    n->left=n->right=NULL;
    return n;
}

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

    if(u==NULL)
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
    else
    {
        u->freq++;
    }
}

int cmp(void *a,void *b)
{
    Node *x=(Node *)a;
    Node *y=(Node *)b;

    if(x->freq < y->freq) return 1;
    if(x->freq > y->freq) return 0;

    return x->ch < y->ch;
}

void inorderTraversal(FILE *fw,BSTNode *root)
{
    if(!root) return;

    inorderTraversal(fw,root->left);

    fwrite(&root->ch,sizeof(unsigned char),1,fw);
    fwrite(&root->freq,sizeof(int),1,fw);

    inorderTraversal(fw,root->right);
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

int main(int argc,char *argv[])
{
    FILE *f,*fw;
    Stack *stk;
    Heap *heap;
    Queue *queue;

    BSTNode *tmp;
    Node *n,*u,*m;

    int succ;
    int e,ch;
    int i,j,x;
    int bit_count,byte_count,totalBits,depth,sz;
    long size;

    unsigned char *bytes;
    char *fileName,*newFileName,*dot;
    char *extension;
    int ext_len;

    if(argc!=2)
    {
        printf("Usage : mgzipper filename\n");
        return 0;
    }

    BSTRoot=NULL;
    root=NULL;
    node_count=0;

    fileName=argv[1];

    f=fopen(fileName,"rb");
    if(!f)
    {
        printf("File not found\n");
        return 0;
    }

    fseek(f,0,SEEK_END);
    size=ftell(f);
    fseek(f,0,SEEK_SET);

    if(size==0)
    {
        printf("Empty file\n");
        return 0;
    }

    while((e=fgetc(f))!=EOF)
        addToBST((unsigned char)e);

    if(node_count==1)
    {
        node_count++;
        if(BSTRoot->ch=='A')
            BSTRoot->right=createBSTNode('B',0);
        else if(BSTRoot->ch<'A')
            BSTRoot->right=createBSTNode('A',0);
        else
            BSTRoot->left=createBSTNode('A',0);
    }

    stk=createStack(&succ);
    heap=createHeap(cmp,&succ);
    queue=createQueue(&succ);

    tmp=BSTRoot;
    while(tmp)
    {
        pushOnStack(stk,tmp,&succ);
        n=createNode(tmp->ch,tmp->freq);
        insert(heap,n,&succ);
        tmp->location=n;
        tmp=tmp->left;
    }

    while(!isStackEmpty(stk))
    {
        tmp=popFromStack(stk,&succ);
        tmp=tmp->right;

        while(tmp)
        {
            pushOnStack(stk,tmp,&succ);
            n=createNode(tmp->ch,tmp->freq);
            insert(heap,n,&succ);
            tmp->location=n;
            tmp=tmp->left;
        }
    }

    while(getSizeOfHeap(heap)>1)
    {
        n=removeFromHeap(heap,&succ);
        u=removeFromHeap(heap,&succ);

        m=createNode('\0',n->freq+u->freq);
        m->left=n;
        m->right=u;
        n->parent=u->parent=m;

        insert(heap,m,&succ);
    }

    root=removeFromHeap(heap,&succ);

    totalBits=0;
    depth=0;

    addToQueue(queue,root,&succ);

    while(!isQueueEmpty(queue))
    {
        sz=getSizeOfQueue(queue);

        for(i=0;i<sz;i++)
        {
            n=removeFromQueue(queue,&succ);
            n->depth=depth;

            if(n->left) addToQueue(queue,n->left,&succ);
            if(n->right) addToQueue(queue,n->right,&succ);

            if(!n->left && !n->right)
                totalBits+=n->depth*n->freq;
        }

        depth++;
    }

    bit_count=totalBits;
    byte_count=(bit_count+7)/8;
    bytes=calloc(byte_count,1);

    dot=strrchr(fileName,'.');
    if(dot)
    {
        extension=dot;
        ext_len=strlen(extension);
    }
    else
    {
        extension="";
        ext_len=0;
    }

    newFileName=malloc(strlen(fileName)+10);
    strcpy(newFileName,fileName);

    dot=strrchr(newFileName,'.');
    if(dot) *dot='\0';

    strcat(newFileName,".mgzip");

    fw=fopen(newFileName,"wb");

    fwrite(&bit_count,sizeof(int),1,fw);
    fwrite(&node_count,sizeof(int),1,fw);
    fwrite(&ext_len,sizeof(int),1,fw);
    fwrite(extension,1,ext_len,fw);

    inorderTraversal(fw,BSTRoot);

    fseek(f,0,SEEK_SET);

    i=0;
    j=0;

    while((ch=fgetc(f))!=EOF)
    {
        tmp=BSTRoot;

        while(tmp)
        {
            if(tmp->ch==(unsigned char)ch) break;
            if(tmp->ch>(unsigned char)ch) tmp=tmp->left;
            else tmp=tmp->right;
        }

        u=tmp->location;

        while(u->parent)
        {
            if(u->parent->right==u)
                pushOnStack(stk,(void *)(intptr_t)1,&succ);
            else
                pushOnStack(stk,(void *)(intptr_t)0,&succ);

            u=u->parent;
        }

        while(!isStackEmpty(stk))
        {
            x=(int)(intptr_t)popFromStack(stk,&succ);

            j<<=1;
            if(x) j|=1;

            i++;

            if(i%8==0)
            {
                bytes[(i/8)-1]=j;
                j=0;
            }
        }
    }

    while(i%8)
    {
        j<<=1;
        i++;
    }

    if(bit_count%8)
        bytes[(i/8)-1]=j;

    fwrite(bytes,1,byte_count,fw);

    fclose(f);
    fclose(fw);

    destroyBST(BSTRoot);
    destroyCBT(root);
    destroyStack(stk);
    destroyQueue(queue);
    destroyHeap(heap);

    free(bytes);
    free(newFileName);

    return 0;
}