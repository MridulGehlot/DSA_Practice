#include<stdio.h>
#include<stdlib.h> //malloc,free
#include<string.h> //memcpy
void swap(void *a,void *b,int elementSize)
{
void *c=malloc(elementSize);
memcpy(c,a,elementSize);
memcpy(a,b,elementSize);
memcpy(b,c,elementSize);
free(c);
}
void bubbleSort(void *arr,int size,int sizeOfElement,int (*ptr2func)(void*,void*))
{
void *a,*b;
int m,e,f;
m=size-2;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
a=arr+(f*sizeOfElement);
b=arr+(e*sizeOfElement);
if(ptr2func(a,b)<0)
{
swap(a,b,sizeOfElement);
}
e++;
f++;
}
m--;
}
}
void print(int *arr,int size)
{
int i=0;
while(i<size)
{
printf("%d\n",arr[i]);
i++;
}
}
int comparator(void *a,void *b)
{
int *left=(int *)a;
int *right=(int *)b;
return (*left)-(*right);
}
int main()
{
int req;
int *arr;
printf("Enter Requirement - ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid Requirement");
return 0;
}
arr=(int *)malloc(sizeof(int)*req);
if(arr==NULL)
{
printf("Unable To Allocate Memory");
return 0;
}
for(int i=0;i<req;i++)
{
printf("Enter A Number - ");
scanf("%d",&arr[i]);
}
bubbleSort(arr,req,sizeof(int),comparator);
printf("----------After Sorting----------\n");
print(arr,req);
free(arr);
return 0;
}

/* 
//Sorting Custom Data
typedef struct student
{
int rollNumber;
char name[20];
}SS;
int comparator(void *a,void *b)
{
SS *left=(SS *)a;
SS *right=(SS *)b;
return ((*left).rollNumber)-((*right).rollNumber);
}
int testMAIN()
{
SS arr[5];
arr[0].rollNumber=103;
sprintf(arr[0].name,"Ramesh");
arr[1].rollNumber=104;
sprintf(arr[1].name,"Suresh");
arr[2].rollNumber=102;
sprintf(arr[2].name,"Ramu");
arr[3].rollNumber=101;
sprintf(arr[3].name,"Mridul");
arr[4].rollNumber=105;
sprintf(arr[4].name,"Rudransh");
bubbleSort(arr,5,sizeof(SS),comparator);
printf("-------After Sorting-------\n");
for(int i=0;i<5;i++)
{
printf("%d,%s\n",arr[i].rollNumber,arr[i].name);
}
return 0;
}
*/