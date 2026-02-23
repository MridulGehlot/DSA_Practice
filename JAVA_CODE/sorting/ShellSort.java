class ShellSort
{
public static void sort(int arr[])
{
int z,y,num,diff;
diff=arr.length/2;
while(diff>=1)
{
y=diff;
while(y<=arr.length-1)
{
num=arr[y];
z=y-diff;
while(z>=0 && arr[z]>num)
{
arr[z+diff]=arr[z];
z-=diff;
}
arr[z+diff]=num;
y++;
}
diff/=2;
}
}
public static void main(String args[])
{
int arr[]={45,12,78,65,98,32,55,60,81,99};
sort(arr);
for(int i=0;i<arr.length;i++) System.out.print(arr[i]+" ");
}
}