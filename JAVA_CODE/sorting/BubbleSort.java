class BubbleSort
{
public static void sort(int arr[])
{
int e,f,m,gg;
m=arr.length-2;
while(m>=0)
{
e=0;
f=e+1;
while(e<=m)
{
if(arr[f]<arr[e])
{
gg=arr[e];
arr[e]=arr[f];
arr[f]=gg;
}
e++;
f++;
}
m--;
}
}
public static void main(String args[])
{
int arr[]={45,12,78,65,98,32,55,60,81,99};
sort(arr);
for(int i=0;i<arr.length;i++) System.out.print(arr[i]+" ");
}
}