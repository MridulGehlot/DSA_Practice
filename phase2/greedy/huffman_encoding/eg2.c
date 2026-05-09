#include<stdio.h>
#include<stdlib.h>
int main()
{
char a[]={"10"};
char b[]={"110"};
char c[]={"111"};
char d[]={"0"};
char data[]={"dabcdaacdd"};
char *code_string;
char code;
unsigned char *bytes;
//encoded 0101101110101011100
int bit_index,byte_index,bit_count,byte_count,e,f,bit_number,tmp,g;
bit_count=19;
byte_count=bit_count/8;
if(bit_count%8!=0) byte_count++;
printf("Number of bits : %d, Number of bytes : %d\n",bit_count,byte_count);
bytes=calloc(byte_count,sizeof(unsigned char));
bit_number=-1;
for(e=0;data[e]!='\0';e++)
{
if(data[e]=='a') code_string=a;
else if(data[e]=='b') code_string=b;
else if(data[e]=='c') code_string=c;
else code_string=d;
for(f=0;code_string[f]!='\0';f++)
{
bit_number++;
byte_index=bit_number/8;
bit_index=7-(bit_number%8);
if(code_string[f]=='1')
{
//do it yourself
bytes[byte_index]|=1<<bit_index;
}
} //loop on code string ends
} //loop on data string ends
//print encoded string (pick byte and filter out the bit (0 or 1) and print it)
printf("Encoded bits : ");
g=0;
for(e=0;e<byte_count;e++)
{
//extract all bits one by one and print either 0 or 1
// for(f=128;f>0;f/=2) printf("%c",((f & bytes[e])==f)?'1':'0');
for(f=7;f>=0;f--) 
{
g++;
tmp=bytes[e]>>f;
if(tmp&1) printf("1");
else printf("0");
if(g>=bit_count) break;
}
if(g>=bit_count) break;
}
printf("\n");
printf("Encoding in characters : ");
for(e=0;e<byte_count;e++)
{
printf("%c",bytes[e]);
}
printf("\n");
free(bytes);
return 0;
}