#include<stdio.h>

int main()
{
int queue[10];
int size=10;
int x;
int ch;
int end=0;
do
{
printf("-----MENU-----\n");
printf("1. Push\n");
printf("2. Pop\n");
printf("3. Print\n");
printf("4. Exit\n");
printf("Enter your Choice : ");
scanf("%d",&ch);

if(ch==1)
{
if(end==size-1) printf("Cannt add to queue, size full\n");
else
{
printf("Enter a Number : ");
scanf("%d",&x);
queue[end++]=x;
}
}
else if(ch==2)
{
if(end==0) printf("Queue is Empty, Cannot pop");
else
{
printf("Poped : %d",queue[0]);
for(int i=0;i<end-1;i++) queue[i]=queue[i+1];
--end;
}
}
else if(ch==3)
{
for(int i=0;i<end;++i) printf("%d ",queue[i]);
printf("\n");
}
}while(ch!=4);

return 0;
}