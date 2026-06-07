#include<stdio.h>
int chess_board[8][8];
int number_of_rows=8;
int number_of_columns=8;
int number_of_blocks=64;
int rows_offset[8]={-2,-1,1,2,2,1,-1,-2};
int cols_offset[8]={1,2,2,1,-1,-2,-2,-1};

int mark_route(int r,int c,int step)
{
int nr,nc;
for(int i=0;i<8;i++)
{
nr=r+rows_offset[i];
nc=c+cols_offset[i];
if(nr>=0 && nr<8 && nc>=0 && nc<8 && chess_board[nr][nc]==0)
{
chess_board[nr][nc]=step+1;
if(chess_board[nr][nc]==number_of_blocks) return 1;
if(mark_route(nr,nc,step+1)==1) return 1;
chess_board[nr][nc]=0;
}
}
return 0;
} 

int generate_knight_route(int r,int c,int step)
{
for(int i=0;i<number_of_rows;i++)
{
for(int j=0;j<number_of_columns;j++)
{
chess_board[i][j]=0;
}
}
chess_board[r][c]=step;
return mark_route(r,c,step);
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
if(generate_knight_route(0,0,1)) print_route();
else printf("No Valid Route possible\n");
return 0;
}