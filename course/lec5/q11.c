/*
char arr[4]={'b','g','h','m'}

i/p -> char
output next smallest character from array
Sample
c -> g
i -> m
r -> b
*/
#include<stdio.h>
int main()
{
char arr[4]={'b','g','h','m'};
char ch;
printf("Enter Character : ");
scanf("%c",&ch);
int ans=0;
for(int i=0;i<4;++i)
{
if(arr[i]>ch)
{
ans=i;
break;
}
}
printf("Next Samllest Character from Array is %c\n",arr[ans]);
return 0;
}