import java.util.*;

public class Sqeuence
{
public static void main(String gg[])
{
int arr[]={12,3,92,-3,76,54,12,93,78};
int vis[]={0,0,0,0,0,0,0,0,0};
List<List<Integer>> finalAnswer=new ArrayList<>();
int prev;
int maxi=0;
for(int i=0;i<arr.length;i++)
{
if(vis[i]==1) continue;
vis[i]=1;
prev=i;
List<Integer> v=new ArrayList<>();
for(int j=i;j<arr.length;j++)
{
if(arr[j]>arr[prev])
{
v.add(prev);
prev=j;
vis[j]=1;
}
}
if(v.size()>0) //push in collection
{
v.add(prev);
if(v.size()>maxi) 
{
maxi=v.size();
finalAnswer.clear();
}
if(v.size()==maxi) finalAnswer.add(v);
}
}
//print the result
for(List<Integer> lst:finalAnswer)
{
for(int idx:lst)
{
System.out.print(arr[idx]+" ");
}
System.out.println();
}

}
}