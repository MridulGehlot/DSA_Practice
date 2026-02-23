class BubbleSort
{
public static void minHeap(int arr[])
{
int y,ci,ri,gg;
y=1;
while(y<arr.length)
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
public static void maxHeap(int arr[])
{
int y,ci,ri,gg;
y=1;
while(y<arr.length)
{
ci=y;
while(ci>0)
{
ri=(ci-1)/2;
if(arr[ci]>arr[ri])
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
public static void main(String args[])
{
int arr[]={45,12,78,65,98,32,55,60,81,99};
minHeap(arr);
for(int i=0;i<arr.length;i++) System.out.print(arr[i]+" ");
System.out.println();
maxHeap(arr);
for(int i=0;i<arr.length;i++) System.out.print(arr[i]+" ");
}
}