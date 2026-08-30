#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
vector<int> arr={12,23,45,56,78,89,90};
auto  it = find_if(arr.begin(),arr.end(),[](int x){
return x%2;
});
cout<<*it<<endl;
return 0;
}