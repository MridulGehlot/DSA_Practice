#include<stdio.h>
int main()
{
char *str="Hello i am Mridul from Ujjain\0";
int i=0;
int count=0;
while(str[i]!='\0')
{
if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u') count++;
i++;
}
printf("Number of Vowels = %d\n",count);
return 0;
}