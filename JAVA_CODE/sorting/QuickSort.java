import java.util.*;
class QuickSort
{
public static int findPP(int arr[],int sp,int ep)
{
int e,f,pivot,gg;
pivot=arr[sp];
e=sp;
f=ep;
while(e<f)
{
while(e<ep && arr[e]<=pivot) e++;
while(f>sp && arr[f]>pivot) f--;
if(e<f)
{
gg=arr[e];
arr[e]=arr[f];
arr[f]=gg;
}
else
{
arr[sp]=arr[f];
arr[f]=pivot;
}
}
return f;
}
public static void sort(int arr[],int sp,int ep)
{
if(sp<ep)
{
int pp=findPP(arr,sp,ep);
sort(arr,sp,pp-1);
sort(arr,pp+1,ep);
}
}
public static void sortIterative(int arr[])
{
int stack[][]=new int[10][2];
int top,lb,ub,pp;
lb=0;
ub=arr.length-1;
top=0;
stack[top][0]=lb;
stack[top][1]=ub;
while(top>=0)
{
lb=stack[top][0];
ub=stack[top][1];
top--;
pp=findPP(arr,lb,ub);
if(pp+1<ub)
{
top++;
stack[top][0]=pp+1;
stack[top][1]=ub;
}
if(pp-1>lb)
{
top++;
stack[top][0]=lb;
stack[top][1]=pp-1;
}
}
}
public static void sortIterativeCollections(int arr[])
{
Stack<int[]> stk=new Stack<>();
stk.push(new int[]{0,arr.length-1});
int lb,ub,pp;
while(!stk.isEmpty())
{
lb=stk.peek()[0];
ub=stk.peek()[1];
stk.pop();
pp=findPP(arr,lb,ub);
if(pp+1<ub) stk.push(new int[]{pp+1,ub});
if(pp-1>lb) stk.push(new int[]{lb,pp-1});
}
}
public static void main(String args[])
{
int arr[]={45,12,78,65,98,32,55,60,81,99};
sort(arr,0,arr.length-1);
System.out.println("Sorted With Recurrsion");
for(int i=0;i<arr.length;i++) System.out.print(arr[i]+" ");

System.out.println("\n");

int arr2[]={45,12,78,65,98,32,55,60,81,99};
sortIterative(arr2);
System.out.println("Sorted With Iterative and self stack");
for(int i=0;i<arr2.length;i++) System.out.print(arr2[i]+" ");

System.out.println("\n");

int arr3[]={45,12,78,65,98,32,55,60,81,99};
sortIterativeCollections(arr3);
System.out.println("Sorted With Iterative and collections stack");
for(int i=0;i<arr3.length;i++) System.out.print(arr3[i]+" ");

}
}