#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void _print_all_combinations(char *array,int index,int bits_count)
{
if(index==bits_count)
{
for(int i=0;i<bits_count;i++) printf("%c ",array[i]);
printf("\n");
return;
}
array[index]='0';
_print_all_combinations(array,index+1,bits_count);
array[index]='1';
_print_all_combinations(array,index+1,bits_count);
}
void print_all_combinations(int bits_count)
{
char *array=(char *)malloc(sizeof(char)*bits_count);
_print_all_combinations(array,0,bits_count);
int numberOfCombinations=pow(2,bits_count);
printf("Total Number of Combinations are %d\n",numberOfCombinations);
free(array);
}

int main()
{
int bits_count;
printf("Enter Number of Bits : ");
scanf("%d",&bits_count);
print_all_combinations(bits_count);
return 0;
}