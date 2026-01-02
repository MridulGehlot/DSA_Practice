#include<bits/stdc++.h>
using namespace std;
int main()
{
int arr[10]={10,-3,7,6,-2,4,3,9,-5,12};
int a,b,sum,target;
sum=0;
target=5;
unordered_map<int,int> mp;
for(int i=0;i<=9;i++)
{
sum+=arr[i];
if(sum==target)
{
a=0;
b=i;
break;
}
if(mp.count(sum-target))
{
a=mp[sum-target]+1;
b=i;
break;
}
mp[sum]=i;
}
printf("Answer in subarry %d to %d on (0 based index)",a,b);
return 0;
}