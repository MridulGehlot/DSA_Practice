class BubbleSort
{
public static void minHeap(int arr[],int ep)
{
int y,ci,ri,gg;
y=1;
while(y<=ep)
{
ci=y;
while(ci>0)
{
ri=(ci-1)/2;
if(arr[ci]<arr[ri])
{
gg=arr[ci];
arr[ci]=arr[ri];
arr[ri]=gg;
ci=ri;
}
else break;
}
y++;
}
}
public static void sort(int arr[])
{
minHeap(arr,arr.length-1);
int y,gg;
y=arr.length-1;
while(y>0)
{
gg=arr[0];
arr[0]=arr[y];
arr[y]=gg;
y--;
minHeap(arr,y);
}
}
public static void main(String args[])
{
int arr[]={45,12,78,65,98,32,55,60,81,99};
sort(arr);
for(int i=0;i<arr.length;i++) System.out.print(arr[i]+" ");
}
}