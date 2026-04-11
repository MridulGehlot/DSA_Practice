#include<iostream>
#include<cstring>
#include<stdexcept>
#define ON 1
#define OFF 0
using namespace std;
class BitArray
{
private:
char *ptr;
int _size;
public:
class Proxy
{
char *ptr;
int idx;
public:
Proxy(char *p,int i) : ptr(p),idx(i) {} ;
Proxy & operator=(int val)
{
int byte=idx/8;
int i=idx%8;
if(val) ptr[byte] |= (1<<i);
else ptr[byte] &= ~(1<<i);
return *this;
}
operator int() const
{
int byte=idx/8;
int i=idx%8;
return (ptr[byte]>>i&1);
}
};
BitArray(unsigned int size,bool initialValue=false);
BitArray(const BitArray &); //copy constructor
BitArray(BitArray &&); //move constructor
~BitArray();
BitArray & operator=(const BitArray &); //assignment operation
BitArray & operator=(BitArray &&); //move assignment operation
bool isOn(unsigned int index) const;
bool isOff(unsigned int index) const;
void turnOn(unsigned int index);
void turnOff(unsigned int index);
unsigned int size() const;
Proxy operator[](int index);
};
BitArray::~BitArray()
{
delete [] ptr;
}
BitArray::BitArray(unsigned int size,bool initialValue)
{
this->_size=size;
int x=size/8;
if(size%8) x++;
ptr=new char[x];
for(int i=0;i<x;i++) ptr[i]=initialValue?(char)0xFF:'\0';
}
BitArray::BitArray(const BitArray &other) //copy constructor
{
this->_size=other.size();
int bytes=(this->_size+7)/8;
this->ptr=new char[bytes];
memcpy(this->ptr,other.ptr,bytes);
}
BitArray::BitArray(BitArray &&other) //move constructor
{
this->ptr=other.ptr;
this->_size=other.size();
other.ptr=NULL;
other._size=0;
}
BitArray & BitArray::operator=(const BitArray &other) //assignment operation
{
if(this==&other) return *this;
delete[] ptr;
_size=other._size;
int bytes=(_size+7)/8;
ptr=new char[bytes];
memcpy(ptr,other.ptr,bytes);
return *this;
}
BitArray & BitArray::operator=(BitArray &&other) //move assignment operation
{
if(this==&other) return *this;
delete[] ptr;
ptr=other.ptr;
_size=other._size;
other.ptr=NULL;
other._size=0;
return *this;
}
bool BitArray::isOn(unsigned int index) const
{
if(index>=this->_size) return false;
int x=index/8;
int bit=index%8;
return ptr[x]>>bit&1;
}
bool BitArray::isOff(unsigned int index) const
{
return !isOn(index);
}
void BitArray::turnOn(unsigned int index)
{
if(index>=this->_size) return;
int x=index/8;
int bit=index%8;
ptr[x] |= (1<<bit);
}
void BitArray::turnOff(unsigned int index)
{
if(index>=this->_size) return;
int x=index/8;
int bit=index%8;
ptr[x] &= ~(1<<bit);
}
unsigned int BitArray::size() const
{
return this->_size;
}
BitArray::Proxy BitArray::operator[](int index)
{
if(index<0 || index>=_size)  throw out_of_range("Index out of range");
return Proxy(ptr,index);
}

int main()
{
BitArray b(5); //other variant BitArray b(5,true) set all bits 1 by default 0
b[0]=true;
b[1]=false;
b[2]=OFF;
b[3]=OFF;
b[4]=ON;
for(int i=0;i<b.size();i++)
{
cout<<b[i]<<endl;
}
return 0;
}