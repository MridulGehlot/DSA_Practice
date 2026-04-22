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
//for Testing
for(auto edge:allEdges)
{
cout<<"("<<edge.first.first<<","<<edge.first.second<<") --> "<<edge.second<<endl;
}

forward_list<pair<string,forward_list<pair<string,int>>>> subGraph;
multiset<pair<pair<string,string>,int>,bool(*)(pair<pair<string,string>,int>,pair<pair<string,string>,int>)> filteredEdges(comparator);

//in the above empty data structure, you need to add the edge if it is not forming a cycle

return 0;
}