#include<stdio.h>
#include<iostream>
#include <stdlib.h>
using namespace std;
typedef struct BiTNode{
	char data;
	struct BiTNode * lchild,*rchild;

}BiTNode,*bitree;

struct stack_tree
{
	bitree base;
	bitree top;
	int stackzise;
};

/*
void Init_stack(stack_tree &l)
{
	l.base = ( bitree* )malloc(100 * sizeof( bitree ));
	if(! l.base) exit (0);
	l.base = l.top;
	l.stackzise = 100;
}
*/
void push_stack(stack_tree &l,bitree e)
{
	if(l.top - l.base >= l.stackzise)
	{
		l.base = (bitree ) realloc ( l.base,(100 + 10) * sizeof (bitree));
	    if(! l.base) exit (0);
	    l.top = l.base + 100;
	}
	l.top = e;
	l.top ++;
}
/*
void pop_stack(stack_tree &l,bitree *e)
{
	if(l.top == l.base) ;
	l.top --;
	e == (bitree *)l.top;
}
int empty_stack(stack_tree &l)
{
	if(l.top == l.base){return 1;}
	else {return 0;}
}


void later_visit_tree(bitree &k) 
{
	stack_tree a;
	stack_tree *base;
	stack_tree *top;
	Init_stack( a );
	bitree p;
	p = k;
	while(p || empty_stack( a ) == 0)
	{
		if(p -> lchild != NULL)
		{
			push_stack(a,p);
			p = p -> lchild;
		}
		else
		{
			if(p -> rchild != NULL)
			{
				push_stack(a,p);
			    p = p -> rchild;
			}
			else
			{
				pop_stack(a,p);
				printf("%c",p -> data);
			}
		}
	}
}
*/

int create_tree(bitree &k)
{
	char ch;
	scanf("%c",&ch);
	if(ch ==' '){
		k = NULL;
	}
	else
	{
		k=(bitree)malloc(sizeof(struct BiTNode));
		k -> data = ch;
		create_tree(k -> lchild);
		create_tree(k -> rchild);
	}
	return 0;
}
int main()
{
	bitree  t;
	t=(bitree ) malloc(sizeof(struct BiTNode));
	create_tree(t);

} 
