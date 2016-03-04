#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define Stacksize 100
#define stackincrement 10
typedef int status;
typedef char selemtype;
typedef struct{
    selemtype *base;
    selemtype *top;
    int stacksize;
}sqstack;
status initstack(sqstack &s){
    s.base=(selemtype *)malloc(Stacksize*sizeof(selemtype));
    if(!s.base) exit (1);
    s.top=s.base;
    s.stacksize=Stacksize;
    return 0;
}
status push(sqstack &s,selemtype e){
    if(s.top-s.base>=s.stacksize){
        s.base=(selemtype *)realloc(s.base,(Stacksize+stackincrement)*sizeof(selemtype));
        if(!s.base) exit(1);
        s.top=s.base+s.stacksize;
        s.stacksize+=stackincrement;
    }
    *s.top=e;
    s.top++;
    return 0;
}
int isp(char x){
    switch(x)
    {
        case '#':return 0;
        case '(':return 1;
        case '*':
        case '/':
        case '%':return 5;
        case '+':
        case '-':return 3;
        case ')':return 6;
        default:return 100;
    }
}
int icp(char x){
    switch(x)
    {
        case '#':return 0;
        case '(':return 6;
        case '*':
        case '/':
        case '%':return 4;
        case '+':
        case '-':return 2;
        case ')':return 1;
        default:return 100;
    }
}
status pop(sqstack &s,selemtype &e){
	e=*--s.top;
	return 0;
}

int main()
{
    char a[100],ch,op,e;int i;
    gets(a);
    sqstack s;
    initstack(s);
    push(s,'#');
    for(i=0;i<strlen(a);i++){
		ch=a[i];op=*(s.top-1);
		if(ch>='0'&&ch<='9'){
			putchar(ch);
		}
		else
		{
			putchar(32);
			if(icp(ch)<isp(op)){
				while(icp(ch)<isp(op)){
				pop(s,e);putchar(e);
				op=*(s.top-1);
				}
			}
			if(icp(ch)>isp(op)){
				push(s,ch);
				continue;
			}
			else 
			pop(s,e);
    	}
	}
    return 0;
}
