#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*remove the duplicate characters in a string With Additional Memory of Constant Size*/
void removeDuplicatesEff(char * str){
    if(str == NULL) return;
    int len = strlen(str);
    if(len<2) return;

    int hit[256];
    for(int i = 0; i<256;++i){
        hit[i] = 0;
    }
    hit[str[0]] = 1;
    int tail =1;
    for(int i = 1; i< len;++i){
        if(!hit[str[i]]){
            str[tail] = str[i];
            ++tail;
            hit[str[i]] = 1;
        }
    }
    str[tail] = 0;
}
int main(){
    char str[] = "asfdasfgsdf";
    removeDuplicatesEff(str);
    printf("%s\n",str);
         
}
