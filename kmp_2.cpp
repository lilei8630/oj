#include<stdio.h>
#include<malloc.h>
#include<iostream>
#include<string.h>
using namespace std;
int next_count[10000] = { 0 };
struct kmp_of_link
{
	char data;
	//struct kmp_of_link *prior;
	struct kmp_of_link *next;
};
kmp_of_link *aa;
int create_link(kmp_of_link *&l)
{
	kmp_of_link *p = NULL,*q = NULL;
	char e='\0';
	l=( kmp_of_link * ) malloc ( sizeof( kmp_of_link ) );
	l -> next = NULL;
	aa = l;
	//p->prior=l;
	while(e != '\n')
	{
		//printf("%p\n",aa);
		p = ( kmp_of_link * ) malloc ( sizeof ( kmp_of_link ) );
		scanf("%c",&e);
		p -> data = e;
		l -> next = p;
		l = p;
		//printf("%c",l->next->data);
	}
	p->next=NULL;
	return 1;
}
int length_link(kmp_of_link *b)
{
	int h = 0;
	while(b -> next != NULL)
	{
		b = b -> next;
		h ++;
	}
	return h-1;
}
int print_link(kmp_of_link *l)
{
	//printf("fuck\n");
	kmp_of_link *a;
	a = l -> next;
	while(1)
	{
		if(a -> next != NULL)
		{
			printf("%c",a -> data);
		    a = a-> next;
		}
	}
	return 1;
}
char get_link(kmp_of_link *b,int i)
{
	for(int j = 0;j <= i;j ++)
	{
		b = b -> next;
	}
	return b -> data;
}
void get_next(kmp_of_link *kk)
{
	int length = length_link( kk );
	//printf("%d\n",length);
	next_count[ 1 ] = 0;
	int i = 1,j = 0;
	while(i < length)
	{
		char kk1 = get_link(kk,j);
		char kk2 = get_link(kk,i);
		//printf("%c\n",kk -> next -> data);
		if(j == 0 || kk1 == kk2 )
		{
			printf("%d %d",j,i);
			++i;
			++j;
			next_count[ i ] = j;
			printf("%c %c %d\n",kk1,kk2,next_count[ i ]);
			continue;
		}
		else
		{
			//printf("%c %c %d %d\n",kk1,kk2,j,i);
			j = next_count[ j ];
		}
		//printf("%c %c %d %d\n",kk1,kk2,j,i);
	}
	
}
int kmp(kmp_of_link *l,kmp_of_link *k)
{
	kmp_of_link *b,*c;
	b = l -> next;
	c = k -> next;
	int length,judge = 0,i = 0,g = 0;	
	while( c -> next == NULL || judge == 1 )
	{
		if(b -> next == NULL){judge = 1;}
		if(c -> data == b -> data)
		{
			c = c -> next;
			b = b -> next;
			i++;
		}
		if(c -> data != b -> data)
		{
			g = i - next_count[ i ];
			//printf("%d\n",g);
			c = k -> next;
			printf("%c\n",k -> next ->data);
			for(int f = g;f > 1;f --)
			{
				b = b -> next;
				if(b == NULL)
				{
					judge = 1;
					break;
				}
			}
			i = 0;
		}
	} 
	return judge;
}
int main()
{
	kmp_of_link *d = NULL;
	kmp_of_link *k = NULL;
	kmp_of_link *ll = NULL;
	kmp_of_link *kk = NULL;
	int j = 0,o=0,length = 0;
	j = create_link(d);
	ll = aa;
	j = create_link(k);
	kk = aa;
	get_next(kk);
	length = length_link(kk);
	for(int i = 1;i <= length;i ++)
	{
		printf("%d\n",next_count[i]);
	}
	o = kmp(ll,kk);
	printf("%d",o);
} 
