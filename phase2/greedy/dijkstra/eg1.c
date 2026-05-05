#include<stdio.h>
#include<stdlib.h>
#include<mg_heap.h>
#include<limits.h>
int distance_from_single_source[7];
int cmp(void *a,void *b)
{
int *x=(int *)a;
int *y=(int *)b;
return distance_from_single_source[*x]<distance_from_single_source[*y];
}
int main()
{
int graph[7][7]={
{0,1,4,2,0,0,0},
{0,0,0,3,0,0,0},
{0,0,0,0,2,0,0},
{0,0,1,0,5,1,0},
{0,0,0,0,0,0,3},
{0,0,0,0,2,0,0},
{0,0,0,0,0,0,0}
};
Heap *heap;
int succ,*x,vertex_index,e,f,g,number_of_vertices,single_source_index,edge_weight,ri,ci;
void *tmp;
int distance_from_single_source_to_adjacent_vertex;
number_of_vertices=7;
int visited[7];
int previous_vertex[7];
char vertex[7]={'A','B','C','D','E','F','G'};
//pre processing
for(e=0;e<number_of_vertices;e++) 
{
visited[e]=0;
previous_vertex[e]=-1;
distance_from_single_source[e]=INT_MAX; 
}
single_source_index=0;
distance_from_single_source[single_source_index]=0;
heap=createHeap(cmp,&succ);
for(e=0;e<number_of_vertices;e++)
{
x=(int *)malloc(sizeof(int));
*x=e;
insert(heap,(void *)x,&succ);
}
//pre processing ends here
//Dijkstra's Algorithm Starts Here
while(getSizeOfHeap(heap)>0)
{
x=removeFromHeap(heap,&succ);
vertex_index=*x;
free(x);
for(e=0;e<number_of_vertices;e++)
{
//There is an edge
if(graph[vertex_index][e]>0)
{
edge_weight=graph[vertex_index][e];
distance_from_single_source_to_adjacent_vertex=distance_from_single_source[vertex_index]+edge_weight;
if(distance_from_single_source_to_adjacent_vertex<distance_from_single_source[e]) //got better
{
previous_vertex[e]=vertex_index;
distance_from_single_source[e]=distance_from_single_source_to_adjacent_vertex;
//find e in heap
for(f=0;getSizeOfHeap(heap);f++)
{
if(*((int *)(heap->collection[f]))==e)
{
ci=f;
break;
}
}
//update heap accourding to new distance
while(ci>0)
{
ri=(ci-1)/2;
if(cmp(heap->collection[ci],heap->collection[ri]))
{
tmp=heap->collection[ci];
heap->collection[ci]=heap->collection[ri];
heap->collection[ri]=tmp;
ci=ri;
}
else break;
}
//update heap accourding to new distance ends here
}
}
}
}
//Algorithm ends here
for(e=0;e<number_of_vertices;e++) printf("Previous Vertex : %d, Vertex : %d, Total Distance %d\n",previous_vertex[e],e,distance_from_single_source[e]);
return 0;
}