#include<iostream>
#include<unordered_set>
using namespace std;
int check(unordered_set<int> arr,int size)
{
return arr.size()==size?0:1;
}
int main()
{
printf("Contains Duplicates : %s\n",(check({1,2,3,4,5},5)==1?"True":"False"));
printf("Contains Duplicates : %s\n",(check({1,2,3,1,5},5)==1?"True":"False"));
return 0;
}