#include<iostream>
using namespace std;
class BitArray
{
private:
unsigned char *ptr;
unsigned int _size;
unsigned int allocationSize;
public:
BitArray(unsigned int size,bool initialValue=false);
BitArray(const BitArray &); //copy constructor
BitArray(BitArray &&); //move constructor
~BitArray();
BitArray & operator=(const BitArray &); //assignment operation
BitArray & operator=(BitArray &&); //move assignment operation
bool isOn(unsigned int index);
bool isOff(unsigned int index);
void turnOn(unsigned int index);
void turnOff(unsigned int index);
unsigned int size() const;
bool operator[](int index);
};
BitArray::~BitArray()
{
delete [] ptr;
}
BitArray::BitArray(unsigned int size,bool initialValue)
{
this->ptr=NULL;
this->_size=size;
this->allocationSize=0;
if(this->_size>0)
{
this->allocationSize=size/8;
if(size%8!=0) this->allocationSize++;
ptr=new unsigned char[this->allocationSize];
unsigned char v;
if(initialValue) v=(unsigned char)255; //all bits set to 1 we could have written 0b11111111
else v=(unsigned char)0; //all bits off
for(int i=0;i<this->allocationSize;i++) ptr[i]=v;
}
}
BitArray::BitArray(const BitArray &other) //copy constructor
{
this->_size=other._size;
this->allocationSize=other.allocationSize;
if(this->_size>0)
{
this->ptr=new unsigned char[this->allocationSize];
for(int i=0;i<this->allocationSize;i++) ptr[i]=other.ptr[i];
}
}
BitArray::BitArray(BitArray &&other) //move constructor
{
this->ptr=other.ptr;
this->_size=other._size;
this->allocationSize=other.allocationSize;
other.ptr=NULL;
other._size=0;
other.allocationSize=0;
}
BitArray & BitArray::operator=(const BitArray &other) //assignment operation
{
if(this==&other) return *this;
if(this->ptr!=NULL) delete [] (this->ptr);
this->_size=other._size;
this->allocationSize=other.allocationSize;
if(this->_size>0)
{
ptr=new unsigned char[this->allocationSize];
for(int i=0;i<this->allocationSize;i++) ptr[i]=other.ptr[i];
}
return *this;
}
BitArray & BitArray::operator=(BitArray &&other) //move assignment operation
{
if(this==&other) return *this;
if(this->ptr!=NULL) delete [] (this->ptr);
this->ptr=other.ptr;
this->_size=other._size;
this->allocationSize=other.allocationSize;
other.ptr=NULL;
other._size=0;
other.allocationSize=0;
return *this;
}
bool BitArray::isOn(unsigned int index)
{
if(index>=this->_size) return false;
unsigned int arrayIndex=index/8;
unsigned int bitIndex=index%8;
bitIndex=7-bitIndex;
int k=1<<bitIndex;
return (this->ptr[arrayIndex]&k)==k;
}
bool BitArray::isOff(unsigned int index)
{
return !isOn(index);
}
void BitArray::turnOn(unsigned int index)
{
if(index>=this->_size) return;
if(isOn(index)) return;
unsigned int arrayIndex=index/8;
unsigned int bitIndex=index%8;
bitIndex=7-bitIndex;
int k=1<<bitIndex;
this->ptr[arrayIndex]=(unsigned char)(this->ptr[arrayIndex]^k);
}
void BitArray::turnOff(unsigned int index)
{
if(index>=this->_size) return;
if(isOff(index)) return;
unsigned int arrayIndex=index/8;
unsigned int bitIndex=index%8;
bitIndex=7-bitIndex;
int k=1<<bitIndex;
this->ptr[arrayIndex]=(unsigned char)(this->ptr[arrayIndex]^k);
}
unsigned int BitArray::size() const
{
return this->_size;
}
bool BitArray::operator[](int index)
{
return isOn(index);
}

int main()
{
BitArray b(8); //other variant BitArray b(5,true) set all bits 1 by default 0
b.turnOn(0);
b.turnOn(1);
b.turnOff(2);
b.turnOff(3);
b.turnOn(4);
b.turnOn(5);
b.turnOn(6);
b.turnOff(7);
for(int i=0;i<b.size();i++)
{
cout<<b[i]<<endl;
}
return 0;
}