#include <stdio.h>

void reverse(char * str){
        char * end = str;
        char tmp;
        if(str){
            while(*end){
                ++end;
            }
            --end;
            while(str<end){
                tmp = *str;
                *str++ = *end;
                *end-- = tmp;
            }
        }
}

int main(){
    char str[] = "abcd";
    //这样是String Literal，str是不可以变的，所以要改写成上面那种格式
    //char * str = "abcd";
    reverse(str);
    printf("%s\n",str);
}

