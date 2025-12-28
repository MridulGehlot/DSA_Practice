#include<stdio.h>
void print(int size,int C[size][size])
{
for(int i=0;i<size;i++)
{
for(int j=0;j<size;j++)
{
printf("%d ",C[i][j]);
}
printf("\n");
}
}
int main()
{
int A[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
int B[4][4]={{10,20,30,40},{50,60,70,80},{90,100,110,120},{130,140,150,160}};
int C[4][4]={{0}};

for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++)
{
for(int k=0;k<4;k++)
{
C[i][j]+=A[i][k]*B[k][j];
}
}
}
print(4,C);
return 0;
}