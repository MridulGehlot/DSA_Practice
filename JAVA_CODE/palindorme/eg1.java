class psp
{
public static boolean isPalindrome(String s,int e,int f)
{
while(e<f)
{
if(s.charAt(e)!=s.charAt(f)) return false;
e++;
f--;
}
return true;
}
public static void main(String gg[])
{
String s="abarrmalayalamrraab";
//Generate all sub strings 
System.out.println("Printing All Sub strings");
int maxi=0;
int start,end;
start=end=0;
for(int i=0;i<s.length();i++)
{
for(int j=i;j<s.length();j++)
{
if(isPalindrome(s,i,j)) 
{
if(j-i+1>maxi)
{
maxi=j-i+1;
start=i;
end=j;
}
System.out.print(s.substring(i,j+1)+" ");
}
}
}
System.out.println("\n LOngest Plaindromic Substring is of legnth - "+maxi+" : ("+s.substring(start,end+1)+")");
}
}