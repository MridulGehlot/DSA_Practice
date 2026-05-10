#include<stdio.h>
#include<stdlib.h>
int main()
{
int number_of_files,*lengths,tapes,e,f,tmp;
double mrt,m;
printf("Enter Number of Files : ");
scanf("%d",&number_of_files);
if(number_of_files<=0)
{
printf("Invalid Number of Files");
return 0;
}
printf("Enter Number of Tapes : ");
scanf("%d",&tapes);
if(tapes<=0)
{
printf("Invalid Number of Tapes");
return 0;
}
lengths=(int *)malloc(sizeof(int)*number_of_files);
printf("Enter Files Lengths : \n");
for(int i=1;i<=number_of_files;i++)
{
printf("File %d : ",i);
scanf("%d",&lengths[i-1]);
}

//sort in ascending order
for(e=0;e<number_of_files-1;e++)
{
for(f=e+1;f<number_of_files;f++)
{
if(lengths[f]<lengths[e])
{
tmp=lengths[f];
lengths[f]=lengths[e];
lengths[e]=tmp;
}
}
}

//calculate MRT(Mean Retrival Time)
mrt=0.0;
for(int i=0;i<number_of_files;i++)
{
mrt+=lengths[i]*(number_of_files-i);
}
mrt=mrt/(number_of_files*1.0);
printf("MRT (Mean Retrival time) = %lf\n",mrt);

//now printing Result
for(int i=0;i<tapes;i++)
{
printf("Tape %d [",i+1);
for(int j=i;j<number_of_files;j+=tapes)
{
printf("%d ",lengths[j]);
}
printf("]\n");
}

free(lengths);
return 0;
}