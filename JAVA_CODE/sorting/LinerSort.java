class LinearSort
{
public static void sort(int arr[])
{
int e,f,gg,ep;
ep=arr.length-2;
e=0;
while(e<=ep)
{
f=e+1;
while(f<arr.length)
{
if(arr[f]<arr[e])
{
gg=arr[f];
arr[f]=arr[e];
arr[e]=gg;
}
f++;
}
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