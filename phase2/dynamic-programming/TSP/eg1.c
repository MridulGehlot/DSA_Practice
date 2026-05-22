#include<stdio.h>
#include<string.h>
void _generate_permutations(char *arr,int start,int length)
{
int e,f,g,ep;
ep=length-1;
for(e=start;e<ep;e++)
{
for(f=e+1;f<=ep;f++)
{
g=arr[e];
arr[e]=arr[f];
arr[f]=g;
_generate_permutations(arr,e+1,length);
g=arr[e];
arr[e]=arr[f];
arr[f]=g;
}
}
printf("%s\n",arr);
}
void generate_permutations(char *arr,int length)
{
_generate_permutations(arr,0,length);
}
int main()
{
char arr[]="ABC";
int len=strlen(arr);
generate_permutations(arr,len);
return 0;
}