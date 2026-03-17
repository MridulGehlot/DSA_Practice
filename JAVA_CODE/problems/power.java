import java.util.Scanner;
public class power
{
private static int arr [];
public static int count;
static {
count=0;
arr=new int[20];
}
public static int power(int x,int y)
{
count++;
if(y==0) return arr[0]=1;
if(y==1) return arr[1]=x;
if(arr[y]!=0) return arr[y];
if(y%2==1) //odd
{
return arr[y]=x*power(x,y/2)*power(x,y/2);
}
else return arr[y]=power(x,y/2)*power(x,y/2);
}
public static void main(String gg[])
{
Scanner sc=new Scanner(System.in);
System.out.println("Enter x and y - ");
int x=sc.nextInt();
int y=sc.nextInt();
int ans=power(x,y);
System.out.println(x+" ,to the power "+y+" is = "+ans);
System.out.println("Count of copies = "+count);
}
}