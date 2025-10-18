#include "selectionSort.c" 
//Sorting Custom Data
typedef struct student
{
int rollNumber;
char name[20];
}SS;
int comp(void *a,void *b)
{
SS *left=(SS *)a;
SS *right=(SS *)b;
return ((*left).rollNumber)-((*right).rollNumber);
}
int main()
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
selectionSort(arr,5,sizeof(SS),comp);
printf("-------After Sorting-------\n");
for(int i=0;i<5;i++)
{
printf("%d,%s\n",arr[i].rollNumber,arr[i].name);
}
return 0;
}