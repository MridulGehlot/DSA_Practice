public class Sqeuence
{
public static void main(String gg[])
{
char arr[]={'a','b','c','d'};
int size=(int)Math.pow(2,arr.length);
for(int i=0;i<size;i++)
{
for(int j=0;j<arr.length;j++)
{
int m=i>>j;
if((m&1)==1) System.out.print(arr[j]);
}
System.out.print(" ");
}

}
}