/*
Just Implement The Logic Of Maxi to find LCS
*/
public class Sqeuence
{
public static void main(String gg[])
{
char x[]={'a','b','c','d'};
char y[]={'a','b','d'};
char temp1[]=new char[4];
char temp2[]=new char[3];
int xi,yi;
int size1=(int)Math.pow(2,x.length);
int size2=(int)Math.pow(2,y.length);
for(int i=1;i<size1;i++)
{
xi=0;
for(int j=0;j<x.length;j++)
{
int m=i>>j;
if((m&1)==1) temp1[xi++]=x[j];
}
//now we have 1 sub sequence of x compare it with all of y
for(int k=1;k<size2;k++)
{
yi=0;
for(int jj=0;jj<y.length;jj++)
{
int mm=k>>jj;
if((mm&1)==1) temp2[yi++]=y[jj];
}
//1 seq of y is ready compare and print
if(xi==yi)
{
int e;
for(e=0;e<xi;e++) if(temp1[e]!=temp2[e]) break;
if(e==yi)
{
for(e=0;e<xi;e++) System.out.print(temp2[e]);
System.out.println();
}
}
}

}

}
}