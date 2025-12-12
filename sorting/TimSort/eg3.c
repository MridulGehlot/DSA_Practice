#include<stdio.h>
#include<stdlib.h>
void merge(int *arr,int l,int m,int r)
{
int len1,len2;
len1=m-l+1;
len2=r-m;
int left[len1],right[len2];
for(int i=0;i<len1;i++) left[i]=arr[l+i];
for(int i=0;i<len2;i++) right[i]=arr[m+1+i];
//compare and merge
int i,j,k;
i=j=0;
k=l;
while(i<len1 && j<len2)
{
if(left[i]<right[j])
{
arr[k++]=left[i];
i++;
}
else
{
arr[k++]=right[j];
j++;
}
}
while(i<len1) arr[k++]=left[i++];
while(j<len2) arr[k++]=right[j++];
}
int min(int l,int r)
{
return l<r?l:r;
}
void insertion_sort(int *nums,int lb,int ub)
{
int y,z,x;
y=lb+1;
while(y<=ub)
{
x=nums[y];
z=y-1;
while(z>=0 && nums[z]>x)
{
nums[z+1]=nums[z];
z--;
}
nums[z+1]=x;
y++;
}
}

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

void timSort(int *arr,int size)
{
for(int i=0;i<size;i+=64) insertion_sort(arr,i,min(i+64-1,size-1));
for(int i=32;i<size;i=2*i)
{
for(int left=0;left<size;left+=2*i)
{
int mid=left+i-1;
int right=min(left+2*i-1,size-1);
if(mid<right) merge(arr,left,mid,right);
}
}

}


int main()
{
FILE *f,*ff;
f=fopen("mainData.dat","rb");
ff=fopen("mergeSortedData.dat","wb");
int length;
fseek(f,0,2);
length=ftell(f);
fseek(f,0,0);
int size=length/sizeof(int);
int index;
int num;
int *arr=malloc(sizeof(int)*size);
index=0;
printf("---Orignial Data---\n");
while(1)
{
if(feof(f)) break;
fread(&num,sizeof(int),1,f);
printf("%d ",num);
arr[index++]=num;
}
//we have already done insertion sort
//simply merge
timSort(arr,size);
printf("\n\n---Sorted Data---\n");
for(int i=0;i<size;i++)
{
num=arr[i];
printf("%d ",num);
fwrite(&num,sizeof(int),1,ff);
}
free(arr);
fclose(f);
fclose(ff);
return 0;
}