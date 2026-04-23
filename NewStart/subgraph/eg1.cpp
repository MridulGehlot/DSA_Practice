#include<stack>
#include<set>
#include<utility>
#include<forward_list>
#include<iostream>
using namespace std;
bool comparator(pair<pair<string,string>,int> left,pair<pair<string,string>,int> right)
{
return left.second<right.second;
}
int main()
{
forward_list<pair<string,forward_list<pair<string,int>>>> graph={
{"A",{{"E",1},{"C",3},{"D",2}}},
{"B",{{"C",3},{"E",2}}},
{"C",{{"B",3},{"D",4},{"A",3}}},
{"D",{{"C",4},{"A",2},{"E",7},{"F",4}}},
{"E",{{"D",7},{"B",2},{"A",1},{"F",5}}},
{"F",{{"E",5},{"D",4}}}
};
//pre processing
multiset<pair<pair<string,string>,int>,bool(*)(pair<pair<string,string>,int>,pair<pair<string,string>,int>)> allEdges(comparator);
auto graphIterator=graph.begin();
while(graphIterator!=graph.end())
{
string vertex=(*graphIterator).first;
auto adjacentVertices=(*graphIterator).second;
auto adjacentVerticesIterator=adjacentVertices.begin();
//cout<<"Vertex : "<<vertex<<endl;
while(adjacentVerticesIterator!=adjacentVertices.end())
{
string adjacentVertex=(*adjacentVerticesIterator).first;
int weight=(*adjacentVerticesIterator).second;
//cout<<"Adjacent Vertex : "<<adjacentVertex<<" , "<<weight<<endl;
allEdges.insert({{vertex,adjacentVertex},weight});
++adjacentVerticesIterator;
}
++graphIterator;
}
//pre processing done

forward_list<pair<string,forward_list<pair<string,int>>>> subGraph;
multiset<pair<pair<string,string>,int>,bool(*)(pair<pair<string,string>,int>,pair<pair<string,string>,int>)> filteredEdges(comparator);
bool cycleFound=false;
bool vertexExistsInSubGraph=false;
//in the above empty data structure, you need to add the edge if it is not forming a cycle

for(auto edge:allEdges)
{
//cout<<"("<<edge.first.first<<","<<edge.first.second<<") --> "<<edge.second<<endl;
string v1=edge.first.first;
string v2=edge.first.second;
int weight=edge.second;
auto iterator=subGraph.begin();
while(iterator!=subGraph.end())
{
stack<pair<string,string>> stk;			//what is this line is moved above the loop
auto subGraphVertex=(*iterator).first;
stk.push({subGraphVertex,string("")});
set<string> visited;				//what is this line is moved above the loop
visited.insert(subGraphVertex);
cycleFound=false;
while(!stk.empty())
{
auto stkElement=stk.top();
stk.pop(); //removed from stack
auto currentVertex=stkElement.first;
auto parentVertex=stkElement.second;
if(v1==currentVertex)
{
if(visited.find(v2)!=visited.end())
{
if(v2!=parentVertex) //cycle found
{
cycleFound=true;
break;
}
}
else
{
stk.push({v2,currentVertex});
visited.insert(v2);
}
}
if(v2==currentVertex)
{
if(visited.find(v1)!=visited.end())
{
if(v1!=parentVertex) //cycle found
{
cycleFound=true;
break;
}
}
else
{
stk.push({v1,currentVertex});
visited.insert(v1);
}
}
for(auto sge:subGraph)
{
if(sge.first==currentVertex)
{
auto adjacentVertices=sge.second; //extracted the forward list
for(auto adjacentVertexPair:adjacentVertices)
{
auto adjacentVertex=adjacentVertexPair.first;
if(visited.find(adjacentVertex)!=visited.end())
{
if(adjacentVertex!=parentVertex)
{
cycleFound=true;
break;
}
} //if adj is found in visited
else
{
stk.push({adjacentVertex,currentVertex});
visited.insert(adjacentVertex);
}
} //loop on adjacent vertices
if(cycleFound) break;
} //if
} //sge loop ends here
if(cycleFound) break;
} //stack loop ends here
if(cycleFound) break;
++iterator;
}//loop on subgraph to check cycle ends here
if(!cycleFound)
{
vertexExistsInSubGraph=false;
for(auto iii=subGraph.begin();iii!=subGraph.end();++iii)
{
if((*iii).first==v1)
{
(*iii).second.push_front({v2,weight});
filteredEdges.insert({{v1,v2},weight});
vertexExistsInSubGraph=true;
break;
}
} //for loop iii
if(!vertexExistsInSubGraph)
{
subGraph.push_front({v1,{{v2,weight}}});
filteredEdges.insert({{v1,v2},weight});
}
}// !cycleFound if
}//allEdges loop ends here

//code to traverse filtered Edges
auto filteredEdgesIterator=filteredEdges.begin();
while(filteredEdgesIterator!=filteredEdges.end())
{
cout<<"("<<(*filteredEdgesIterator).first.first<<"-"<<(*filteredEdgesIterator).first.second<<")-->"<<(*filteredEdgesIterator).second<<endl;
++filteredEdgesIterator;
}

return 0;
}