#include<stdio.h>
#define EXPECTED_FILES 5
int findPP(int *arr,int lb,int ub)
{
int e,f,num,tmp;
num=arr[lb];
e=lb;
f=ub;
while(e<f)
{
while(e<=ub && arr[e]<=num) e++;
while(arr[f]>num) f--;
if(e<f)
{
tmp=arr[f];
arr[f]=arr[e];
arr[e]=tmp;
}
else
{
arr[lb]=arr[f];
arr[f]=num;
}
}
return f;
}
void quickSort(int *arr,int lb,int ub)
{
if(lb<ub)
{
int pp=findPP(arr,lb,ub);
quickSort(arr,lb,pp-1);
quickSort(arr,pp+1,ub);
}
}
int main()
{
FILE *f;
f=fopen("mainData.dat","rb");
fseek(f,0,SEEK_END);
int lengthOfFile=ftell(f);
fseek(f,0,0);
int numberOfNumbers=lengthOfFile/sizeof(int);
printf("Total Number - %d",numberOfNumbers);
int numbersInEachFile=numberOfNumbers/EXPECTED_FILES;
FILE *files[EXPECTED_FILES];
char str[20];
for(int i=0;i<EXPECTED_FILES;i++)
{
sprintf(str,"data%d.dat",(i+1));
files[i]=fopen(str,"wb");
}
int count=0;
int index=0;
int num,k;
k=0;
int arr[1001];
while(1)
{
if(feof(f)) break;
fread(&num,sizeof(int),1,f);
count++;
if((index!=EXPECTED_FILES-1) && (count==numbersInEachFile))
{
quickSort(arr,0,count-1);
for(int i=0;i<count;i++)
{
num=arr[i];
fwrite(&num,sizeof(int),1,files[index]);
}
count=0;
k=0;
index++;
}
arr[k]=num;
k++;
}
//sort last file
quickSort(arr,0,count-1);
for(int i=0;i<count;i++)
{
num=arr[i];
fwrite(&num,sizeof(int),1,files[index]);
}
for(int i=0;i<EXPECTED_FILES;i++) fclose(files[i]);
fclose(f);
return 0;
}