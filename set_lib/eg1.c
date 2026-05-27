#include<stdio.h>
#include<stdlib.h>
typedef struct
{
char hashmap[26];
int size;
}char_set;

char_set * construct_char_set()
{
int i;
char_set *s;
s=(char_set *)malloc(sizeof(char_set));
if(s)
{
for(i=0;i<26;i++) s->hashmap[i]=(char)0;
s->size=0;
}
return s;
}

void destroy_char_set(char_set *s)
{
if(!s) return;
free(s);
}

int char_set_hash_function(char ch)
{
int hashkey=-1;
if(ch>=97 && ch<=122) hashkey=(ch-32)-65;
else if(ch>=65 && ch<=90) hashkey=ch-65;
return hashkey;
}

void _add_to_char_set(char_set *s,char ch)
{
if(!s) return;
int added=0;
int hashkey=char_set_hash_function(ch);
if(hashkey==-1) return;
if(s->hashmap[hashkey]==(char)0) added=1;
s->hashmap[hashkey]=ch;
if(added) s->size++;
}

void _process_and_add_to_char_set(char_set *s,const char * ptr)
{
const char *start=ptr;
while(*ptr)
{
if((*ptr>=97 && *ptr<=122) || (*ptr>=65 && *ptr<=90))
{
if(ptr==start)
{
ptr++;
continue;
}
if(*(ptr+1)=='\0')
{
ptr++;
continue;
}
if(*(ptr-1)=='\'' && *(ptr+1)=='\'') _add_to_char_set(s,*ptr);
}
ptr++;
}
}

int contains_in_char_set(char_set *s,char ch)
{
if(!s) return 0;
int hashkey=char_set_hash_function(ch);
if(hashkey==-1) return 0;
return s->hashmap[hashkey]!=(char)0;
}

void print_char_set(char_set *s)
{
if(!s) return;
if(s->size==0) return;
int i;
for(i=0;i<26;i++)
{
if(s->hashmap[i]!=(char)0) 
{
printf("%c",s->hashmap[i]);
if(i<25) printf(",");
}
}
printf("\n");
}

void remove_from_char_set(char_set *s,char element)
{
if(!s || s->size==0) return;
int hashkey=char_set_hash_function(element);
if(hashkey==-1) return;
if(s->hashmap[hashkey]==(char)0) return;
s->hashmap[hashkey]=(char)0;
s->size--;
}

int get_char_set_size(char_set *s)
{
if(!s) return 0;
return s->size;
}

char get_element_of_char_set(char_set *s,int index)
{
int i,j;
if(!s) return (char)0;
if(index<0 || index>=s->size) return (char)0;
j=-1;
for(i=0;i<26;i++)
{
if(s->hashmap[i]!=(char)0)
{
j++;
if(j==index) return s->hashmap[i];
}
}
return (char)0;
}

char_set * clone_char_set(char_set *s)
{
if(!s) return s;
int i;
char_set *t=(char_set *)malloc(sizeof(char_set));
for(i=0;i<26;i++) t->hashmap[i]=s->hashmap[i];
t->size=s->size;
return t;
}

#define add_to_char_set(ss,...) _process_and_add_to_char_set(ss,#__VA_ARGS__)

int main()
{
int x;
char_set *t,*s;
s=construct_char_set();
add_to_char_set(s,'A');
add_to_char_set(s,'B','C','D');
if(contains_in_char_set(s,'C')) printf("C is part of set\n");
else printf("C is not part of set\n");
add_to_char_set(s,'C','E','A');
print_char_set(s);
printf("Number of elements in set %d\n",get_char_set_size(s));
remove_from_char_set(s,'B');
printf("After Removing, Number of Elements in set %d\n",get_char_set_size(s));
for(x=0;x<get_char_set_size(s);x++)
{
printf("%c ",get_element_of_char_set(s,x)); //0 indexed
}
t=clone_char_set(s);
printf("\nContents of The Cloned set after adding some elements\n");
add_to_char_set(t,'K','Z');
for(x=0;x<get_char_set_size(t);x++)
{
printf("%c ",get_element_of_char_set(t,x)); //0 indexed
}
destroy_char_set(t);
destroy_char_set(s);
return 0;
}