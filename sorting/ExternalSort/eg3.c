#include<stdio.h>
#define EXPECTED_FILES 5
FILE *files[EXPECTED_FILES];
void merge()
{
int numberOfFiles=EXPECTED_FILES;
int arr[numberOfFiles];
int num;
for(int i=0;i<numberOfFiles;i++)
{
if(feof(files[i]))
{
for(int k=i;k<numberOfFiles-1;k++)
{
fclose(files[k]);
files[k]=files[k+1];
numberOfFiles--;
}
//closing 1 file and shift others
}//if EOF
fread(&num,sizeof(int),1,files[i]);
arr[i]=num;
}//for loop ends here
FILE *ff=fopen("sorted.dat","wb");
int smallest;
int index;
while(numberOfFiles)
{
smallest=arr[0];
index=0;
for(int i=1;i<numberOfFiles;i++)
{
if(arr[i]<smallest)
{
smallest=smallest;
index=i;
}
}
fwrite(&smallest,sizeof(int),1,ff);
if(feof(files[index]))
{
fclose(files[index]);
FILE *tmp=files[numberOfFiles-1];
files[numberOfFiles-1]=files[index];
files[index]=tmp;
numberOfFiles--;
arr[index]=999999;
}
fread(&arr[index],sizeof(int),1,files[index]);
}//while ends here
fclose(ff);
}
void openAll()
{
char str[20];
for(int i=0;i<EXPECTED_FILES;i++)
{
sprintf(str,"data%d.dat",(i+1));
files[i]=fopen(str,"rb");
}
}
void closeAll()
{
for(int i=0;i<EXPECTED_FILES;i++)
{
fclose(files[i]);
}
}
void print()
{
printf("\nExternal Sorting Done\n\n");
printf("Before Sorting\n");
int num;
FILE *f=fopen("mainData.dat","rb");
while(1)
{
fread(&num,sizeof(int),1,f);
printf("%d ",num);
if(feof(f)) break;
}
fclose(f);
printf("\nAfter Sorting\n");
f=fopen("sorted.dat","rb");
while(1)
{
fread(&num,sizeof(int),1,f);
printf("%d ",num);
if(feof(f)) break;
}
fclose(f);
}
int main()
{
openAll();
merge();
//closeAll();
print();
}