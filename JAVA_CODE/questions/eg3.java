//Find Missing number (not distinct)
import java.util.*;
class psp
{
public static List<Integer> sol1(int arr[],int n)
{
int [] temp=new int[n];
for(int x:arr) temp[x-1]++;
List<Integer> lst=new ArrayList<>();
for(int i=0;i<temp.length;i++) if(temp[i]==0) lst.add(i+1);
return lst;
}
public static List<Integer> sol2(int arr[],int n)
{
for(int x:arr) if(arr[Math.abs(x-1)]>0) arr[Math.abs(x)-1]*=-1;
List<Integer> lst=new ArrayList<>();
for(int i=0;i<n;i++) if(arr[i]>=0) lst.add(i+1);
return lst;
}
public static void main(String gg[])
{
int arr[]={2,3,3,3,4,2,3,3};
List<Integer> ans1=sol1(arr,5);
List<Integer> ans2=sol2(arr,5);
System.out.println("Missing Numbers are : ");
for(int x:ans1) System.out.print(x+" ");
System.out.println();
for(int x:ans2) System.out.print(x+" ");
}
}