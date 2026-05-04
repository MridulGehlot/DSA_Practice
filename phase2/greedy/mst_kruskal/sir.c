#include<stdio.h>
int main()
{
int graph[4][4]={
{0,1,4,0},
{1,0,2,2},
{4,2,0,3},
{0,2,3,0}
};
int mst[4][4]={
{0,0,0,0},
{0,0,0,0},
{0,0,0,0},
{0,0,0,0}
};
typedef struct _edge
{
int vertex1_index;
int vertex2_index;
int weight;
}edge;
int v1_set_id,v2_set_id;
edge tmp;
edge edges[6];
int set_ids[4]={0,1,2,3};
int edges_count=0;
int r,c,found,e,f;
int number_of_vertices=4;

//create edges data structure
for(r=0;r<number_of_vertices;r++)
{
for(c=0;c<number_of_vertices;c++)
{
if(graph[r][c]>0)
{
for(found=0,e=0;e<edges_count;e++)
{
if(edges[e].vertex1_index==c && edges[e].vertex2_index==r)
{
found=1;
break;
}
}
if(found) continue;
edges[edges_count].vertex1_index=r;
edges[edges_count].vertex2_index=c;
edges[edges_count].weight=graph[r][c];
edges_count++;
}
}
}
//sort data structure by weight
for(e=0;e<edges_count-1;e++)
{
for(f=e+1;f<edges_count;f++)
{
if(edges[f].weight<edges[e].weight)
{
tmp=edges[e];
edges[e]=edges[f];
edges[f]=tmp;
}
}
}

//print sorted data
for(e=0;e<edges_count;e++) printf("%d\n",edges[e].weight);

for(e=0;e<edges_count;e++)
{
v1_set_id=set_ids[edges[e].vertex1_index];
v2_set_id=set_ids[edges[e].vertex2_index];
if(v1_set_id!=v2_set_id)
{
//add edge to MST
mst[edges[e].vertex1_index][edges[e].vertex2_index]=edges[e].weight;
//perform union
for(f=0;f<4;f++) if(set_ids[f]==v1_set_id) set_ids[f]=v2_set_id;
}
}
//print MST
for(r=0;r<number_of_vertices;r++)
{
for(c=0;c<number_of_vertices;c++)
{
printf("%4d ",mst[r][c]);
}
printf("\n");
}
return 0;
}