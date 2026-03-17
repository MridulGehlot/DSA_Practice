public class distinct_combinations
{
public static void combinations(char arr[],int start,int end)
{
if(start==end)
{
for(int i=0;i<arr.length;i++) System.out.print(arr[i]);
System.out.print(" ");
return;
}
char g;
for(int i=start;i<=end;i++)
{
g=arr[i];
arr[i]=arr[start];
arr[start]=g;
combinations(arr,start+1,end);
g=arr[i];
arr[i]=arr[start];
arr[start]=g;
}
}
public static void main(String gg[])
{
char arr[]=new char[4];
arr[0]='h';
arr[1]='i';
arr[2]='j';
arr[3]='k';
combinations(arr,0,3);
}
}