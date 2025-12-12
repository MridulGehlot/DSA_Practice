#include<stdio.h>
int getLen(const char *str)
{
int i=0;
while(str[i]!='\0') i++;
return i;
}
int main()
{
char str[101];
printf("Enter a String - ");
fgets(str,100,stdin);
for(int i=0;i<100;i++)
{
if(str[i]=='\n')
{
str[i]='\0';
break;
}
}
printf("Length of String - %d",getLen(str));
return 0;
}