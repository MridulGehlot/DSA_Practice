#include<stdio.h>
int chess_board[8][8];
int number_of_rows=8;
int number_of_columns=8;

int absolute(int num)
{
if(num<0) return num*-1;
return num;
}

int _place_queen(int column)
{
int r1,c1,r2,c2,can_place;
c2=column;
for(r2=0;r2<8;++r2) // try placing the queen in all rows
{
can_place=1; //assume we can place
for(c1=0;c1<column;++c1) //check all prev columns
{
//find queen and break if exists
for(r1=0;r1<8;++r1)
{
if(chess_board[r1][c1]) break;
}
if(r1==r2 || absolute(r2-r1)==absolute(c2-c1))
{
can_place=0;
break;
}
}
if(can_place)
{
chess_board[r2][c2]=1;
if(column==7) return 1;
if(_place_queen(c2+1)) return 1;
chess_board[r2][c2]=0;
}
}
return 0;
}

int place_queen()
{
for(int i=0;i<number_of_rows;i++)
{
for(int j=0;j<number_of_columns;j++)
{
chess_board[i][j]=0;
}
}
return _place_queen(0);
}

void print_route()
{
printf("     ");
for(int i=0;i<number_of_columns;i++) printf("(%d) ",i+1);
printf("\n");
for(int i=0;i<number_of_rows;i++)
{
printf("(%d) ",i+1);
for(int j=0;j<number_of_columns;j++)
{
printf("%4d",chess_board[i][j]);
}
printf("\n");
}
}

int main()
{
if(place_queen()) print_route();
else printf("No Valid placement possible\n");
return 0;
}