//This is without padding Code consider everyone as center
class psp
{
public static int expand(String s,int e,int f)
{
int count=-1;
while(e<s.length() && f>=0)
{
if(s.charAt(e)!=s.charAt(f)) return count;
count+=2;
e++;
f--;
}
return count;
}
public static void main(String gg[])
{
String s="abarrmalayalamrraab";
int arr[]=new int[s.length()];
int maxi,idx,start;
maxi=0;
idx=0;
for(int i=0;i<arr.length;i++)
{
arr[i]=expand(s,i,i);
if(arr[i]>maxi)
{
maxi=arr[i];
idx=i;
}
}
//what is s is of even size and its palindrome
if(s.length()%2==0)
{
int mid=s.length()/2;
int res=expand(s,mid-1,mid);
if(res>maxi)
{
maxi=res;
idx=mid-1;
}
}
int buffer=(maxi-1)/2;
System.out.println("Longest Plaindromic Substring is of legnth - "+maxi);
System.out.println(s.substring(idx-buffer,maxi+2));
}
}