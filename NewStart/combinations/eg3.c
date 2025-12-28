#include<stdio.h>
#include<string.h>
int count=0;
void swap(char *a,char *b)
{
char c=*a;
*a=*b;
*b=c;
}
void _printAllCombinations(char *str,int start,int end)
{
if(start==end)
{
for(int i=0;i<=end;i++) printf("%c",str[i]);
printf(" ");
count++;
return;
}
for(int i=start;i<=end;i++)
{
swap(&str[i],&str[start]);
_printAllCombinations(str,start+1,end);
swap(&str[i],&str[start]);
}
}
void printAllCombinations(char *str,int setSize)
{
_printAllCombinations(str,0,setSize-1);
}
int main()
{
char set[100];
printf("Enter set - ");
fgets(set,100,stdin);
int len=strlen(set);
set[len-1]='\0';
printAllCombinations(set,len-1);
printf("\nNumber of combinations - %d\n",count);
return 0;
}