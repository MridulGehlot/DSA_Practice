/*
Count Number of Rooms Required For Meetings
[start,end] time -> m
Determine Number of Rooms Required

Approach
Priority queue (min heap)
*/
#include<bits/stdc++.h> //to include everything

using namespace std;

int main()
{
vector<pair<int,int>> meetings={
{4,17},
{7,10},
{15,20},
{20,30},
{27,90},
{32,56}
};

int cnt=0;
//priority_queue<int> pq; //by default max heap in cpp but in java by default is min heap
priority_queue<int,vector<int>,greater<int>> pq;

for(auto m:meetings)
{
auto [start_time,end_time] = m;
if(pq.empty())
{
++cnt;
pq.push(end_time);
}
else
{
if(start_time>pq.top()) //reuse
{
pq.pop();
pq.push(end_time);
}
else //new room is required
{
++cnt;
pq.push(end_time);
}
}
}
cout<<"Number of Rooms Required is : "<<cnt<<endl;
return 0;
}