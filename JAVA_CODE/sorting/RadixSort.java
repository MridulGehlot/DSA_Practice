import java.util.*;
class RadixSort
{
public static void sort(int arr[])
{
Queue<Integer>[] q=new ArrayDeque[10];
for(int i=0;i<10;i++) q[i]=new ArrayDeque<>();
int largest,dc,e,f;
largest=Arrays.stream(arr).max().getAsInt();
dc=String.valueOf(largest).length();
e=10;
f=1;
int temp,idx;
while(dc>0)
{
for(int i=0;i<arr.length;i++)
{
temp=arr[i]%e;
idx=temp/f;
q[idx].offer(arr[i]);
}
idx=0;
for(int i=0;i<=9;i++)
{
while(q[i].isEmpty()==false)
{
arr[idx++]=q[i].poll();
}
}
dc--;
e*=10;
f*=10;
}
}
public static void main(String gg[])
{
int arr[]={45,12,78,65,98,32,55,60,81,99};
sort(arr);
for(int i=0;i<arr.length;i++) System.out.print(arr[i]+" ");
}
}