#include<iostream>
using namespace std;
int main()
{
bool flag;
string s1="MADAM";
string s2="SIR";
flag=true;
cout<<"String s1 = "<<s1<<endl;
for(int i=0,j=s1.size()-1;i<j;i++,j--)
{
if(s1[i]!=s1[j]) 
{
flag=false;
cout<<"Not a Palindrome"<<endl;
break;
}
}
if(flag) cout<<"Palindrome"<<endl;
flag=true;
cout<<"String s2 = "<<s2<<endl;
for(int i=0,j=s2.size()-1;i<j;i++,j--)
{
if(s1[i]!=s1[j]) 
{
flag=false;
cout<<"Not a Palindrome"<<endl;
break;
}
}
if(flag) cout<<"Palindrome"<<endl;
return 0;
}