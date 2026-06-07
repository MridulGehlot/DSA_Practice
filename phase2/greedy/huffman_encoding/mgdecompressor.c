#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mg_heap.h>

typedef struct _Node
{
    unsigned char ch;
    int freq;
    struct _Node *left,*right,*parent;
} Node;

Node *createNode(unsigned char ch,int freq)
{
    Node *n=(Node *)malloc(sizeof(Node));
    n->ch=ch;
    n->freq=freq;
    n->left=n->right=n->parent=NULL;
    return n;
}

int cmp(void *a,void *b)
{
    Node *x=(Node *)a;
    Node *y=(Node *)b;

    if(x->freq < y->freq) return 1;
    if(x->freq > y->freq) return 0;

    return x->ch < y->ch;
}

void destroyTree(Node *r)
{
    if(!r) return;
    destroyTree(r->left);
    destroyTree(r->right);
    free(r);
}

int main(int argc,char *argv[])
{
    FILE *f,*fw;
    Heap *heap;
    Node *n,*u,*m,*root,*curr;

    int succ;
    int bit_count,node_count,ext_len;
    int i,freq;
    int total_bits_read=0;
    int bit;

    unsigned char ch;
    unsigned char byte;

    char *fileName,*newFileName,*dot;
    char extension[100];

    if(argc!=2)
    {
        printf("Usage : mgdecompressor somefile.mgzip\n");
        return 0;
    }

    fileName=argv[1];

    f=fopen(fileName,"rb");
    if(f==NULL)
    {
        printf("File does not exist\n");
        return 0;
    }

    // Read header
    fread(&bit_count,sizeof(int),1,f);
    fread(&node_count,sizeof(int),1,f);
    fread(&ext_len,sizeof(int),1,f);

    if(ext_len>0)
    {
        fread(extension,1,ext_len,f);
    }
    extension[ext_len]='\0';

    heap=createHeap(cmp,&succ);

    // Read character-frequency pairs
    for(i=0;i<node_count;i++)
    {
        fread(&ch,sizeof(unsigned char),1,f);
        fread(&freq,sizeof(int),1,f);

        n=createNode(ch,freq);
        insert(heap,n,&succ);
    }

    // Rebuild Huffman tree
    while(getSizeOfHeap(heap)>1)
    {
        n=removeFromHeap(heap,&succ);
        u=removeFromHeap(heap,&succ);

        m=createNode('\0',n->freq+u->freq);
        m->left=n;
        m->right=u;

        n->parent=m;
        u->parent=m;

        insert(heap,m,&succ);
    }

    root=removeFromHeap(heap,&succ);

    // Create output filename
    newFileName=(char *)malloc(strlen(fileName)+strlen(extension)+20);
    strcpy(newFileName,fileName);

    dot=strrchr(newFileName,'.');
    if(dot) *dot='\0';

    strcat(newFileName,"_restored");
    strcat(newFileName,extension);

    fw=fopen(newFileName,"wb");
    if(fw==NULL)
    {
        printf("Cannot create output file\n");
        fclose(f);
        destroyTree(root);
        return 0;
    }

    curr=root;

    // Decode exactly bit_count bits
    while(total_bits_read < bit_count)
    {
        fread(&byte,sizeof(unsigned char),1,f);

        for(i=7;i>=0 && total_bits_read<bit_count;i--)
        {
            bit=(byte>>i)&1;

            if(bit==0)
                curr=curr->left;
            else
                curr=curr->right;

            if(curr->left==NULL && curr->right==NULL)
            {
                fwrite(&curr->ch,sizeof(unsigned char),1,fw);
                curr=root;
            }

            total_bits_read++;
        }
    }

    fclose(f);
    fclose(fw);

    destroyHeap(heap);
    destroyTree(root);
    free(newFileName);

    printf("Decompression completed successfully\n");

    return 0;
}