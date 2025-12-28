#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count=0;
void _printAllCombinations(char *seed,char *set,int setSize,int length)
{
if(length==0)
{
printf("%s ",seed);
count++;
return;
}
int i,seedLength;
char *str;
seedLength=strlen(seed);
//1 for new char and 1 for \0
str=(char *)malloc(sizeof(char)*(seedLength+2));
strcpy(str,seed);
for(int i=0;i<setSize;i++)
{
str[seedLength]=set[i];
str[seedLength+1]='\0';
_printAllCombinations(str,set,setSize,length-1);
}
free(str);
}
void printAllCombinations(char *set,int setSize,int length)
{
_printAllCombinations("",set,setSize,length);
}
int main()
{
//char set[4]={'0','1','2','3'};
char set[100];
printf("Enter set - ");
fgets(set,100,stdin);
int len=strlen(set);
set[len-1]='\0';
printAllCombinations(set,len-1,3);
printf("\nNumber of combinations set^3 - %d\n",count);
return 0;
}