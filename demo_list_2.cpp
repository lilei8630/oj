#include<iostream>
#include<string.h>
using namespace std;
struct test_stack
{
	char * base;
	char * top;
	int stacksize;
};
char test;
int init_stack(test_stack &l)
{
	l.base = (char * ) malloc ( 100 * sizeof(char));
	if(!l.base) exit (0);
	l.top = l.base;
	l.stacksize = 100;
	return 1; 
}
int push_stack(test_stack &l,char e)
{

	// printf("!!!\n");
	if(l.top-l.base >= l.stacksize)
	{
		l.base = (char * ) realloc ( l.base,(l.stacksize + 10) * sizeof (char));
	    if(!l.base) exit (0);
	    l.top = l.base + l.stacksize;
	}
	* l.top = e;
	 l.top ++;
	
	return 1;
}
int pop_stack(test_stack &l,char &e)
{
	if(l.top == l.base)return 0;
	l.top --;
	e = *l.top;
	return 1;
}
void Infix_to_Suffix(char* infix, char* suffix)
{
	printf("I_T_S_infix:%s\n",infix );
	test_stack k;
	test_stack * top;
	test_stack * base;
	char a1,a2,o='#';
	int judge;
	judge = init_stack(k);
	judge = push_stack(k,o);
	int i = 0;
	int index=0;

	for(i = 0; infix[i] != '\0';i ++)
	{
		a1=infix[i];
		printf("infix[%d]=%c\n",i,infix[i]);
		
		if(a1 == '0' || a1 == '1' || a1 == '2' || a1 == '3' ||
		 a1 == '4' || a1 == '5' || a1 == '6' || a1 == '7' || a1 == '8' || a1 == '9')
		{
			 suffix[index++] = a1;
			 continue;
		}
		else if(a1 == '(')
		{
			judge = push_stack(k,a1);
		}
		else if(a1 == ')')
		{
			while(*(k.top-1) != '(')
			{
				judge = pop_stack(k,*suffix);
				suffix++;
			}
			k.top--;
		}
		else if(a1 == '*'||a1 == '/')
		{
			if(*k.top == '*'||*k.top == '/')
			{
				judge = pop_stack(k,suffix[index++]);
				suffix++;
			}
			judge = push_stack(k,a1);
		}
		else if(a1 == '+'||a1 == '-')
		{
			//printf("a1:%c\n",a1);
			//printf("*(k.top-1):%c\n", *(k.top-1));

			while(*(k.top-1) != '(' && *(k.top-1) != '#')
			{
				judge = pop_stack(k,suffix[index++]);
			}			

			judge = push_stack(k,a1);
		}
	} 
	judge = pop_stack(k,suffix[index++]);
} 
int main()
{
	test_stack s;
	test_stack * top;
	test_stack * base;
	char * infix,*suffix;
	infix=(char *)malloc(1000*sizeof(char));
	suffix=(char *)malloc(1000*sizeof(char));
	scanf("%s",infix);
	//printf("input:%s\n",infix );
	Infix_to_Suffix(infix,suffix);
	printf("%s",suffix);
}
