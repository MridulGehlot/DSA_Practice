//Find Missing Number in a list
/*
give n distinct numbers find 1 missing in the range 0 to n;
*/
import static java.lang.System.out;
class psp
{
public static int sol1(int arr[])
{
int n=arr.length;
int sum=0;
for(int i=0;i<arr.length;i++) sum+=arr[i];
int total_sum=(n*(n+1)/2);
return total_sum-sum;
}
public static int sol2(int arr[])
{
int ans=0;
for(int i=0;i<arr.length;i++)
{
ans^=i;
ans^=arr[i];
}
ans^=arr.length;
return ans;
}
public static void main(String gg[])
{
int arr[]={5,0,4,3,1};
out.println("Missing Number is");
out.println("Method 1 (total_sum) : "+sol1(arr));
out.println("Method 2 (XOR) : "+sol2(arr));
}
}