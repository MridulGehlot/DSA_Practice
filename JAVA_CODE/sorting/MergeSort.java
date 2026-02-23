import java.util.*;
class MergeSort
{
public static void merge(int arr[],int sp,int mid,int ep)
{
int e,f,k,size;
size=ep-sp+1;
if (size <= 0) return;
int temp[]=new int[size];
k=0;
e=sp;
f=mid+1;
while(e<=mid && f<=ep)
{
if(arr[e]<arr[f])
{
temp[k++]=arr[e];
e++;
}
else
{
temp[k++]=arr[f];
f++;
}
}
while(e<=mid)
{
temp[k++]=arr[e];
e++;
}
while(f<=ep)
{
temp[k++]=arr[f];
f++;
}
f=0;
e=sp;
while(f<k)
{
arr[e++]=temp[f];
f++;
}
}
public static void sort(int arr[],int sp,int ep)
{
if(sp<ep)
{
int mid=(sp+ep)/2;
sort(arr,sp,mid);
sort(arr,mid+1,ep);
merge(arr,sp,mid,ep);
}
}
public static void sortIterative(int arr[])
{
int stack[][]=new int[10][2];
int stack2[][]=new int[10][2];
int top,lb,ub,pp,top2;
lb=0;
ub=arr.length-1;
top=0;
top2=0;
stack[top][0]=lb;
stack[top][1]=ub;
while(top>=0)
{
lb=stack[top][0];
ub=stack[top][1];
top--;
stack2[top2][0]=lb;
stack2[top2][1]=ub;
top2++;
pp=(lb+ub)/2;
if(lb<pp)
{
top++;
stack[top][0]=lb;
stack[top][1]=pp;
}
if(pp+1<ub)
{
top++;
stack[top][0]=pp+1;
stack[top][1]=ub;
}
}
top2--;
while(top2>=0)
{
lb=stack2[top2][0];
ub=stack2[top2][1];
pp=(lb+ub)/2;
merge(arr,lb,pp,ub);
top2--;
}
}
public static void sortIterativeCollections(int arr[])
{
Stack<int[]> stk=new Stack<>();
Stack<int[]> stk2=new Stack<>();
stk.push(new int[]{0,arr.length-1});
int lb,ub,mid;
while(!stk.isEmpty())
{
lb=stk.peek()[0];
ub=stk.peek()[1];
stk2.push(new int[]{lb,ub});
stk.pop();
mid=(lb+ub)/2;
if(mid+1<ub) stk.push(new int[]{mid+1,ub});
if(lb<mid) stk.push(new int[]{lb,mid});
}
while(!stk2.isEmpty())
{
int p[]=stk2.pop();
lb=p[0];
ub=p[1];
mid=(lb+ub)/2;
merge(arr,lb,mid,ub);
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