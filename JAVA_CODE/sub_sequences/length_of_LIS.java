public class Sqeuence
{
public static void main(String gg[])
{
int arr[]={12,3,92,-3,76,54,12,93,78};
int dist[]={1,1,1,1,1,1,1,1,1};
for(int f=1;f<arr.length;f++)
{
for(int e=0;e<f;e++)
{
if(arr[f]>arr[e])
{
dist[f]=Math.max(dist[e]+1,dist[f]);
}
}
}
int maxi=0;
for(int i=0;i<dist.length;i++) maxi=Math.max(maxi,dist[i]);
System.out.println("Maximum Length of LIS is "+maxi);
}
}