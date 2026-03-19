class psp
{
public static int expand(String s,int idx)
{
int e,f;
e=f=idx;
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
StringBuilder sb=new StringBuilder();
sb.append("!");
for(char ch:s)
{
sb.append(ch);
sb.append("!");
}
String edit=sb.toString();
int arr[]=new int[edit.length()];
int maxi,idx,start;
maxi=0;
for(int i=0;i<arr.length;i++)
{
arr[i]=expand(edit,i);
if(arr[i]>maxi)
{
maxi=arr[i];
idx=i;
}
}
/*
int sz=(maxi-1)/2;
if(edit.charAt(idx)=='!')
{
start=idx-sz;
sz++;
}
else
*/
System.out.println("\n LOngest Plaindromic Substring is of legnth - "+maxi);
}
}