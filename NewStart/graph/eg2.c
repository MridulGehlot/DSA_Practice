#include<stdio.h>
int main()
{
char vertices[6]={'A','B','C','D','E','F'};
int graph[2][6][6]={
{
{1,3,2,-1,-1,-1},
{4,-1,-1,-1,-1,-1},
{5,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1},
{3,-1,-1,-1,-1,-1},
{4,-1,-1,-1,-1,-1}
},
{
{4,5,1,0,0,0},
{2,0,0,0,0,0},
{1,0,0,0,0,0},
{0,0,0,0,0,0},
{1,0,0,0,0,0},
{1,0,0,0,0,0}
}
};
int path[6][2]={
{-1,0},
{-1,0},
{-1,0},
{-1,0},
{-1,0},
{-1,0}
};
char src,dst;
int srcIndex,dstIndex,heapSize,lci,rci,ri,ci,sci,top,lastIndex,i,j,adv,edge,sum;
printf("Enter Source (A,B,C,D,E,F) : ");
src=getchar();
fflush(stdin);
srcIndex=-1;
for(i=0;i<6;i++)
{
if(src==vertices[i]) srcIndex=i;
}
if(srcIndex==-1)
{
printf("Invalid Source %c\n",src);
return 0;
}
printf("Enter Destination (A,B,C,D,E,F) : ");
dst=getchar();
fflush(stdin);
dstIndex=-1;
for(i=0;i<6;i++)
{
if(dst==vertices[i]) dstIndex=i;
}
if(dstIndex==-1)
{
printf("Invalid Destination %c\n",dst);
return 0;
}
typedef struct _element
{
int vertex;
int totalDistanceFromSource;
}Element;
Element heap[100];
Element g,e;
e.vertex=srcIndex;
e.totalDistanceFromSource=0;
heapSize=0;
heap[heapSize]=e;
heapSize++;

path[srcIndex][0]=srcIndex;

//Apply Algo
while(heapSize>0)
{
e=heap[0];
if(e.vertex==dstIndex) break;
heap[0]=heap[heapSize-1];
heapSize--;
if(heapSize>0) //then only adjust heap
{
ri=0;
lastIndex=heapSize-1;
while(ri<lastIndex)
{
lci=(2*ri)+1;
rci=lci+1;
if(lci>lastIndex) break;
if(rci>lastIndex) sci=lci;
else
{
if(heap[lci].totalDistanceFromSource<heap[rci].totalDistanceFromSource) sci=lci;
else sci=rci;
}
//now we found sci
if(heap[ri].totalDistanceFromSource<heap[sci].totalDistanceFromSource)
{
g=heap[ri];
heap[ri]=heap[sci];
heap[sci]=g;
ri=sci;
}
else break;
} //ri<lastIndex loop
} //heap adjust loop ends here

//now traverse Adjacent vertices
for(i=0;i<6 && graph[0][e.vertex][i]!=-1;i++)
{
adv=graph[0][e.vertex][i];
edge=graph[1][e.vertex][i];
sum=e.totalDistanceFromSource+edge;
if(path[adv][0]==-1 || sum<path[adv][1]) //add to heap
{
path[adv][0]=e.vertex;
path[adv][1]=sum;
g.vertex=adv;
g.totalDistanceFromSource=sum;
heap[heapSize]=g;
heapSize++;
//now we added new child in heap float it up
ci=heapSize-1;
while(ci>0)
{
ri=(ci-1)/2;
if(heap[ci].totalDistanceFromSource<heap[ri].totalDistanceFromSource)
{
g=heap[ci];
heap[ci]=heap[ri];
heap[ri]=g;
ci=ri;
}
else break;
} //while ci>0
} //if added to heap ends here
//else we will skip this
}
} //main while loop ends here
if(e.vertex!=dstIndex)
{
printf("No Valid Path Exists from %c to %c",src,dst);
return 0;
}
int stack[6];
top=6;
top--;
stack[top]=dstIndex;
ci=dstIndex;
while(1)
{
top--;
ci=path[ci][0];
stack[top]=ci;
if(ci==srcIndex) break;
}
//printing the result
i=0;
printf("Node | dist | total Distnace\n");
while(top!=6)
{
j=stack[top];
i=path[j][1]-i;
printf("%c | %d | %d\n",vertices[j],i,path[j][1]);
i=path[j][1];
top++;
}
return 0;
}