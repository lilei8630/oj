#include <stdio.h>
#include <stdlib.h>
#define selemtype char
typedef struct
{
	selemtype * base;
	selemtype * top;
	int stacksize;
}sqstack;
int initstack(sqstack &s)
{
	s.base=(selemtype *)malloc(20*sizeof(selemtype));
	if(!s.base)exit(0);
	s.top=s.base;
	s.stacksize=20;
	return 1;
}
int gettop(sqstack s,selemtype &e)
{
	if(s.top==s.base)
	return 0;
	e=*(s.top-1);
	return 1;
}
int push(sqstack &ss,selemtype a)
{
	printf("push:%c\n",a);
	if(ss.top-ss.base>=ss.stacksize)
	{ 
		ss.base=(selemtype *)realloc(ss.base,(ss.stacksize+10)*sizeof(selemtype));
		if(!ss.base)
		exit(0);
		ss.top=ss.base+ss.stacksize;
		ss.stacksize+=10;
	}
	*ss.top = a;
	printf("1");
	ss.top++;
	return 1;
}
int pop(sqstack &s,selemtype &e)
{
	if(s.top==s.base )
	return 0;
	e=*--s.top;
	return 1;
}
int main()
{
	selemtype a;
	sqstack s;
	initstack(s);
	scanf("%c",&a);
	printf("input:%c\n",a);
	push(s,a);	
	do
	{
		scanf("%c",&a);
		printf("%c",a);
		push(s,a);
		if(a>='0'&&a<='9')
		printf("%c",a);
		else
		{
			switch(a)
			{
				case '-':
				case '+':a='2';break;
				case '(':a='6';break;
				case '*':
				case '/':
				case '%':a='4';break;
				case ')':a='1';break;
				case '#':a='0';break;
			}
			char c;
			gettop(s,c);
			switch(c)
			{
				case '-':
				case '+':c='3';break;
				case '(':c='1';break;
				case '*':
				case '/':
				case '%':c='5';break;
				case ')':c='6';break;
				case '#':c='0';break;
			}
			if(a>c)
			push(s,a);
			else if(a<c)
			{
				pop(s,a);
				printf("%c",a);
			}
			else if(a==c)
			{
				if(c!='1')
				pop(s,a);
			}
		}
	}while(a!='#');	
} 
