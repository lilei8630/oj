#include <string.h> 
#include <stdlib.h> 
#include <stdio.h> 

typedef struct olnode
{
	int i,j;
	int e;
	struct olnode *right,*down;
}olnode,*olink;

typedef struct
{
	olink *rhead,*chead;
	int mu,nu,tu;
}crosslist;
void create(crosslist *m)
{
	int o,n,t,i,j,e;
	olink p,q;
	scanf("%d%d%d",&o,&n,&t);
	m->mu=o;
	m->nu=n;
	m->tu=t;
	//printf("%d %d %d",m->mu,m->nu,m->tu);
	if(!(m->rhead=(olink*)malloc((o+1)*sizeof(olink)))) exit(-1);
	if(!(m->chead=(olink*)malloc((n+1)*sizeof(olink)))) exit(-1);
	for (int i = 0; i < o; ++i)
	{
		m->rhead[i]=NULL;
	}
	for (int i = 0; i < n; ++i)
	{
		m->chead[i]=NULL;
	}
	for(scanf("%d%d%d",&i,&j,&e);i!=0;scanf("%d%d%d",&i,&j,&e))
	{
		
		p=(olink)malloc(sizeof(olnode));

		p->i=i;
		p->j=j;
		p->e=e;
		//printf("i:%d j:%d e:%d\n",i,j,e);
		if(m->rhead[i]==NULL||m->rhead[i]->j>j)
		{
			p->right=m->rhead[i];
			m->rhead[i]=p;
		}
		else
		{
			for(q=m->rhead[i];q->right&&q->right->j<j;q=q->right);
			p->right=q->right;
			q->right=p;
		}
		if(m->chead[j]==NULL||m->chead[j]->i>i)
		{
			p->down=m->chead[j];
			m->chead[j]=p;
		}
		else
		{
			for(q=m->chead[j];q->down&&q->down->i<i;q=q->down);
			p->down=q->down;
			q->down=p;
		}
	}
}

int main()
{
	crosslist *A,*B;
	create(A);
	
	
	return 0;
}
