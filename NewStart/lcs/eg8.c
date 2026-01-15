#include<stdio.h>
int main()
{
int x[6]={65,66,67,68,80,90};
int y[4]={66,90,68,90};
int xLen,yLen,rows,cols,a,b,maxi,ans,idxX,idxY,idxZ,size;
xLen=6;
yLen=4;
rows=xLen+1;
cols=yLen+1;
int mat[rows][cols];
size=xLen<yLen?xLen:yLen;
int arr[size];
idxZ=size-1;

//set 0th row and 0th col to 0
for(int i=0;i<rows;i++) mat[i][0]=0;
for(int i=0;i<cols;i++) mat[0][i]=0;

ans=0;
for(int i=1;i<rows;i++)
{
for(int j=1;j<cols;j++)
{
a=x[i-1];
b=y[j-1];
if(a==b)
{
//diagonal left element
maxi=mat[i-1][j-1];
mat[i][j]=maxi+1;
if(mat[i][j]>ans) 
{
idxX=i;
idxY=j;
ans=mat[i][j];
}
}
else
{
//max from top and left side
maxi=mat[i-1][j]>mat[i][j-1]?mat[i-1][j]:mat[i][j-1];
mat[i][j]=maxi;
}
}
}
while(idxX>0 && idxY>0)
{
if(x[idxX-1]==y[idxY-1])
{
//move diagonally
arr[idxZ--]=x[idxX-1];
idxX--;
idxY--;
}
else if(mat[idxX-1][idxY]>=mat[idxX][idxY-1]) idxX--;
else idxY--;
}
//imp
idxZ++;
printf("Length of LCS is %d\n",ans);
printf("Elements are -> ");
while(idxZ<size)
{
printf("%d ",arr[idxZ]);
idxZ++;
}
return 0;
}