public class Sqeuence
{
public static void main(String gg[])
{
int arr[]={12,3,92,-3,76,54,12,93,78};
int vis[]={0,0,0,0,0,0,0,0,0};
int prev;
for(int i=0;i<arr.length;i++)
{
if(vis[i]==1) continue;
vis[i]=1;
prev=arr[i];
boolean moreThenOne=false;
for(int j=i;j<arr.length;j++)
{
if(arr[j]<prev)
{
System.out.print(prev+" ");
moreThenOne=true;
prev=arr[j];
vis[j]=1;
}
}
if(moreThenOne) System.out.println(prev);
}

}
}