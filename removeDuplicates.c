#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*remove the duplicate characters in a string without using any additional buffer*/
void removeDuplicates(char * str) {
        if(str == NULL) return;
        int len = strlen(str);
        if(len < 2 ) return;
        int tail = 1;
        for(int i =1;i<len;i++){
            int j;
            for(j=0;j<tail;++j){
                if(str[i] == str[j]) break;
            }
            if(j==tail){
                str[tail] = str[i];
                ++tail;
            }
        }
        str[tail] = 0;
}
int main(){
        char str[] = "";
        removeDuplicates(str);
        printf("%s\n",str);
}



