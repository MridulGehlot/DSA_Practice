class psps
{
public static int solve(int wt[],int val[],int cap,int idx)
{
if(cap<=0 || idx==wt.length) return 0;
int pick=-1;
if(cap>=wt[idx]) pick=val[idx]+solve(wt,val,cap-wt[idx],idx+1);
int nopick=solve(wt,val,cap,idx+1);
return Math.max(pick,nopick);
}
public static void main(String gg[])
{
int [] wt={1,5,10,15,20,22};
int [] val={5,2,6,4,5,3};
int cap=25;
System.out.println("Max Profit we can make - "+solve(wt,val,cap,0));
}
}