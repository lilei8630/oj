#include <stdlib.h>
#include <stdio.h>
typedef struct lnode
{
    char data;
    struct lnode *next;
}lnode,*linklist;
int initlinklist(linklist &l)
{
    l=(lnode *)malloc(100*sizeof(lnode));
    if(!l) exit (1);
    else return 0;
}
int insertlinklist(linklist &l,char x,int i)
{
    linklist p=l;
    int j=0;
    while(p&&j<i-1)
    {
        p=p->next;j++;
    }
    if(!p||j>i-1)
        return 1;
    linklist s=(linklist)malloc(sizeof(lnode));
    s->data=x;p->next=s;
    return 0;
}
int index_kmp(linklist l,linklist ll,int next[])
{
    linklist pl=l->next,pll=ll->next;
    int i=1,j=1;
    while(pl&&pll)
    {
        if(j==0||pl->data==pll->data)
        {
            i++;pll=pll->next;
            j++;pl=pl->next;
        }
        else
        {
            j=next[j];pl=l;
            for(int k=0;k<j;k++)
                pl=pl->next;
        }
    }
    if(!pl)
        return i-j+1;
    else
        return 0;
}
void get_next(linklist l,int next[])
{
    int i=1,j=0;
    next[1]=0;
    linklist pa=l,pb=l;
    while(pa)
    {
        if(j==0||pa->data==pb->data)
        {
            i++;pa=pa->next;
            j++;pb=pb->next;
            next[i]=j;
        }
        else
        {
            j=next[j];pb=l;
            for(int k=0;k<j;k++)
                pb=pb->next;
        }
    }
}
int main()
{
    linklist l,ll;
    int next[100],i,j;
    initlinklist(l);
    initlinklist(ll);
    char a[100],b[100];
    gets(a);
    for(i=1,j=0;a[j]!='\0';i++,j++)
        insertlinklist(ll,a[j],i);
    gets(b);
    for(i=1,j=0;b[j]!='\0';i++,j++)
        insertlinklist(l,b[j],i);
    get_next(l,next);
    printf("%d",index_kmp(l,ll,next));
    return 0;
}
