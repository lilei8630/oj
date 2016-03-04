#include <stdio.h>
#include <stdlib.h> 
typedef unsigned int uint32;
uint32 _hash_log2(uint32 num)
{
    uint32 i,
           limit;
    limit =1;
    for(i=0;limit<num;limit<<=1,i++);
    return i;
}

int main()
{
    printf("%d",_hash_log2(8));
    return 0;
}
