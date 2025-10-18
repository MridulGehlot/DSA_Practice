#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
int min=1;
int max=10000;
int num;
srand(time(NULL));
FILE *f;
f=fopen("mainData.dat","wb");
if(f==NULL)
{
printf("Unable To Open A File\n");
return 0;
}
for(int i=1;i<=500;i++)
{
num=(rand()%(max-min+1))+min;
printf("%d ",num);
fwrite(&num,sizeof(int),1,f);
}
fclose(f);
return 0;
}