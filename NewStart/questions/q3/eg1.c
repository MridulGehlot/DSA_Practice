//Find missing numbers given numbers from 1 to n
#include<stdio.h>
#include<stdlib.h>
struct MissingNumbers
{
int *elements;
int size;
};
struct MissingNumbers findMissingElement(int *x,int sz,int n)
{
int e,f;
struct MissingNumbers missingNumbers;
missingNumbers.elements=(int *)calloc(sizeof(int),n);
for(e=0;e<sz;e++)
{
missingNumbers.elements[x[e]-1]++;
}
for(e=0,f=0;e<n;e++)
{
//printf("idx - %d, count - %d, f - %d\n",e,missingNumbers.elements[e],f);
if(missingNumbers.elements[e]==0)
{
missingNumbers.elements[f]=e+1;
f++;
}
}
//printf("\n");
missingNumbers.size=f;
return missingNumbers;
}

int main()
{
int x[9]={2,3,3,3,4,2,3,3,3};
struct MissingNumbers missingNumbers=findMissingElement(x,9,5);
if(missingNumbers.size==0)
{
printf("Nothing is Missing\n");
}
else
{
for(int i=0;i<missingNumbers.size;i++)
{
printf("%d ",missingNumbers.elements[i]);
}
}
free(missingNumbers.elements);
return 0;
}