#include<stdio.h>
#define MAXN 101  // Adjust based on constraints

int knapsack01(int wt[], int val[], int n, int req);  // Prototype

int main() {
    int n, cap;
    printf("Enter Number of Items: ");
    scanf("%d", &n);
    
    printf("Enter Knapsack Capacity: ");
    scanf("%d", &cap);
    
    int wt[n], val[n];
    
    printf("Enter %d weights: ", n);
    for(int i = 0; i < n; i++) scanf("%d", &wt[i]);
    
    printf("Enter %d values: ", n);
    for(int i = 0; i < n; i++) scanf("%d", &val[i]);
    
    int result = knapsack01(wt, val, n, cap);
    printf("Maximum value: %d\n", result);
    
    return 0;
}

int _get(int wt[], int val[], int n, int cap,int index)
{
if(cap<=0 || index==n) return 0;
int x,y;
x=y=0;
if(cap>=wt[index])
{
x=val[index]+_get(wt,val,n,cap-wt[index],index+1);
}
y=_get(wt,val,n,cap,index+1);
return x>y?x:y;
}
int knapsack01(int wt[], int val[], int n, int cap) 
{
return _get(wt,val,n,cap,0);
}
