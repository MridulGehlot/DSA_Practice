#include<stdio.h>
#define RUN 32
void insertionSort(int *arr,int size)
{
if(size==1) return;
int y,z,num;
y=1;
while(y<size)
{
num=arr[y];
z=y-1;
while(z>=0 && arr[z]>num)
{
arr[z+1]=arr[z];
z--;
}
arr[z+1]=num;
y++;
}
}
void write(FILE *f,int *arr,int size)
{
for(int i=0;i<size;i++) fwrite(&arr[i],sizeof(int),1,f);
}
int main()
{
FILE *f,*ff;
int arr[RUN];
f=fopen("mainData.dat","rb");
ff=fopen("insertionSortedData.dat","wb");
int index=0;
int num;
while(1)
{
if(feof(f)) break;
fread(&num,sizeof(int),1,f);
arr[index++]=num;
if(index==RUN)
{
insertionSort(&arr[0],index);
write(ff,&arr[0],index);
index=0;
}
}
if(index!=0)
{
insertionSort(&arr[0],index);
write(ff,&arr[0],index);
index=0;
}
fclose(f);
fclose(ff);
return 0;
}