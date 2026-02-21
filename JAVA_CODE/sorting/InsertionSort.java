class InsertionSort
{
public static void sort(int arr[])
{
int z,y,num;
y=1;
while(y<=arr.length-1)
{
num=arr[y];
z=y-1;
while(z>=0 && arr[z]>num)
{
arr[z+1]=arr[z];
z--;
}
arr[z+1]=num;
y++;
}
}
public static void main(String args[])
{
int arr[]={45,12,78,65,98,32,55,60,81,99};
sort(arr);
for(int i=0;i<arr.length;i++) System.out.print(arr[i]+" ");
}
}