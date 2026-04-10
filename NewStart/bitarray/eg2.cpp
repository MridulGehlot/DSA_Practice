#include<iostream>
using namespace std;
class BitArray
{
private:
char *ptr;
int _size;
public:
BitArray(unsigned int size,bool initialValue=false);
BitArray(const BitArray &); //copy constructor
BitArray(BitArray &&); //move constructor
BitArray & operator=(const BitArray &); //assignment operation
BitArray & operator=(BitArray &&); //move assignment operation
bool isOn(unsigned int index);
bool isOff(unsigned int index);
void turnOn(unsigned int index);
void turnOff(unsigned int index);
unsigned int size();
};
BitArray::BitArray(unsigned int size,bool initialValue=false);
BitArray::BitArray(const BitArray &); //copy constructor
BitArray::BitArray(BitArray &&); //move constructor
BitArray & BitArray::operator=(const BitArray &); //assignment operation
BitArray & BitArray::operator=(BitArray &&); //move assignment operation
bool BitArray::isOn(unsigned int index);
bool BitArray::isOff(unsigned int index);
void BitArray::turnOn(unsigned int index);
void BitArray::turnOff(unsigned int index);
unsigned int BitArray::size();

int main()
{
BitArray b(5); //other variant BitArray b(5,true) set all bits 1 by default 0
b.turnOn(0);
b.turnOn(1);
b.turnOff(2);
b.turnOff(3);
b.turnOn(4);
for(int i=0;i<b.size();i++)
{
cout<<b[i]<<endl;
}
return 0;
}