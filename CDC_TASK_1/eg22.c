#include<stdio.h>
int main()
{
int x;
do
{
printf("(-1 to stop) Enter Grade (1-100) : ");
scanf("%d",&x);
if (x == -1) {
break; // Exit the loop if -1 is entered
} else if (x >= 0 && x < 30) {
printf("Fail\n");
} else if (x >= 30 && x < 60) {
printf("C++\n");
} else if (x >= 60 && x < 90) {
printf("B++\n");
} else if (x >= 90 && x <= 100) {
printf("A++\n");
} else {
printf("Invalid grade entered (must be 1-100 or -1 to stop).\n");
}
}while(x!=-1);
return 0;
}