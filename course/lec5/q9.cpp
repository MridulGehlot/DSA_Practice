/*
Meeting rooms 
Determine Can You Attend All Meetings
Approach -> sort all meetings and identify and conflicts
*/
#include<bits/stdc++.h> //to include everything

using namespace std;

int main()
{
vector<pair<int,int>> meetings={
{4,17},
{17,20},
{20,30},
{31,90},
};

sort(meetings.begin(),meetings.end()); //according to start time

int prev_end_time=0;
bool can_attend_all_meetings=true;

// 1-5 4-9 5-7 

for(auto m:meetings)
{
if(m.first>=prev_end_time) prev_end_time=m.second;
else 
{
can_attend_all_meetings=false;
break;
}
}

cout<<"can_attend_all_meetings : "<<can_attend_all_meetings<<endl;
return 0;
}