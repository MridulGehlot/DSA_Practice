#include<stdio.h>
int graph[4][4]={
{0,1,1,0},
{1,0,1,1},
{1,1,0,1},
{0,0,1,0}
};
char vertices[]="ABCD";
int number_of_vertices=4;

void find_hamiltonian_paths(char *set,int idx)
{
if(idx==number_of_vertices)
{
if(graph[set[0]-'A'][set[idx-1]-'A']==1)
{
set[idx]='\0';
printf("%s\n",set);
}
return;
}
int exists;
for(int i=0;i<number_of_vertices;++i) //try to place all
{
exists=0;
//check if previously exists
for(int prev=0;prev<idx;++prev)
{
if(set[prev]==vertices[i])
{
exists=1;
break;
}
}
if(!exists) //not exists and there is a path between them
{
if(idx==0 || (idx!=0 && graph[vertices[i]-'A'][set[idx-1]-'A']==1))
{
set[idx]=vertices[i];
find_hamiltonian_paths(set,idx+1);
}
}
}
}

int main()
{
char set[number_of_vertices+1];
printf("Hamiltonian Paths Are\n");
find_hamiltonian_paths(set,0);
return 0;
}