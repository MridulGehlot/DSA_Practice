class SelectionSort
{
public static void sort(int arr[])
{
int e,num,si,f;
e=0;
while(e<=arr.length-2)
{
si=e;
f=e+1;
while(f<=arr.length-1)
{
if(arr[f]<arr[si]) si=f;
f++;
}
num=arr[e];
arr[e]=arr[si];
arr[si]=num;
e++;
}
}
public static void main(String args[])
{
int arr[]={45,12,78,65,98,32,55,60,81,99};
sort(arr);
for(int i=0;i<arr.length;i++) System.out.print(arr[i]+" ");
}
}