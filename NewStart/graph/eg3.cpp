#include<iostream>
#include<forward_list>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

template<typename V,typename W>
class WeightedGraph
{
vector<V> vertices;
unordered_map<V,vector<pair<V,W>>> adjList;
public:
void addVertex(V node)
{
vertices.push_back(node);
}
void addEdge(V from,V to,W distance)
{
adjList[from].push_back({to,distance});
}
forward_list<pair<V,W>> getRoute(V from,V to)
{
forward_list<pair<V,W>> route;
if(from==to)
{
route.push_front({from,0});
return route;
}
priority_queue<pair<W,V>,vector<pair<W,V>>,greater<pair<W,V>>> pq;
unordered_map<V,W> visited;
unordered_map<V,pair<V,W>> parent;
pq.push({0,from});
visited[from]=0;
parent[from]={from,0};
while(!pq.empty())
{
auto top=pq.top();
W dist=top.first;
V node=top.second;
pq.pop();
if(node==to) break;
if(adjList.count(node)==false) continue;
for(auto neighbour:adjList[node])
{
V nn=neighbour.first;
W cost=neighbour.second+dist;
if(visited.count(nn)==false || cost<visited[nn])
{
//push to queue
pq.push({cost,nn});
visited[nn]=cost;
parent[nn]={node,neighbour.second};
}
}
}
//check if path Exists
if(parent.count(to)==0) return route;
//Now BackTrack The Path
V curr=to;
while(curr!=from)
{
route.push_front({curr,parent[curr].second});
curr=parent[curr].first;
}
route.push_front({from,0});
return route;
}
};

int main()
{
WeightedGraph<string,int> graph; //string (city name) / int (distance)
graph.addVertex("UJJAIN");
graph.addVertex("INDORE");
graph.addVertex("DEWAS");
graph.addVertex("MHOW");
graph.addVertex("RAU");

graph.addEdge("UJJAIN","INDORE",45); //from,to,distance
graph.addEdge("UJJAIN","DEWAS",36);
graph.addEdge("DEWAS","INDORE",25);
graph.addEdge("INDORE","MHOW",19);
graph.addEdge("MHOW","RAU",170);

forward_list<pair<string,int>> route; // string(city) , int (distance to next city int the route)
route=graph.getRoute("UJJAIN","RAU");
//route=graph.getRoute("INDORE","UJJAIN");
//if route(forward_list) contains an entry then iterate and print else print no route exists

cout<<"Printing Path\n";
bool pathExists=false;
for(auto &p:route)
{
pathExists=true;
cout<<p.first<<" "<<p.second<<endl;
}
if(!pathExists) cout<<"Oops!!! No Path Exists"<<endl;
return 0;
}