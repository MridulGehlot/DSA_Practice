public class combinations
{
public static void combinations(String seed,int arr[],int length)
{
if(length==0)
{
System.out.print(seed+" ");
return;
}
length--;
for(int i=0;i<arr.length;i++)
{
String g=seed+arr[i];
combinations(g,arr,length);
}
}
public static void main(String gg[])
{
int arr[]=new int[4];
for(int i=0;i<4;i++) arr[i]=i;
combinations("",arr,3);
}
}