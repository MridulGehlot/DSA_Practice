// Determine array has duplicates
import java.util.*;
class psp
{
public static boolean sol1(int arr[])
{
for(int i=0;i<arr.length;i++)
{
for(int j=i+1;j<arr.length;j++)
{
if(arr[i]==arr[j]) return true;
}
}
return false;
}
public static boolean sol2(int arr[])
{
Set<Integer> st=new HashSet<>();
for(int i=0;i<arr.length;i++)
{
if(st.contains(arr[i])) return true;
st.add(arr[i]);
}
return false;
}
public static void main(String gg[])
{
int arr[]={12,45,32,78,98,22};
int arr2[]={12,45,32,78,98,45};
System.out.println("Solution 1 n^2/1 2 loop : "+sol1(arr));
System.out.println("Solution 2 n/n using hash set : "+sol2(arr2));
}
}