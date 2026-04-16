#include<iostream>
using namespace std;
class aaa
{
public:
operator int()
{
return 250;
}
};
int main()
{
aaa a;
cout<<a;
return 0;
}