/*������������ָ����ǰ���ͺ�̵�ָ��Ϊ������*/ 
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define Link 0     //���Һ��� 
#define Thread 1   //ǰ���ͺ�̣������� 
typedef struct BiTNode               //������ÿ�����ṹ 
{
	char data;
	int ltag,rtag;              
	struct BiTNode *lchild,*rchild;  //���Һ���ָ�� 
}BiTNode,*BiTree;
BiTNode *s[MAX]={NULL};
BiTNode *Thrt,*pre;
void create_T(BiTree &T)   //����������������һ������������������ֵ 
{
	BiTNode *q;
	int i;
	char x=' ';
	//printf("������ֵ:\n");
	while(x!='$')                 //���������־x='$' 
	{
		scanf("%d %c",&i,&x); 
		if(x=='$')break;          
		q=(BiTNode *)malloc(sizeof(BiTNode));   //�����½�� 
		q->data=x,q->lchild=NULL,q->rchild=NULL;
		s[i]=q;         //�½���ַ����ָ��������
		if(i==1)T=q;    //��i=1��Ӧ�Ľ���Ǹ����
		else        
		{
			if(i%2==0)s[i/2]->lchild=q,s[i/2]->ltag=0;  //��˫�׽�����ϵ 
			else s[i/2]->rchild=q,s[i/2]->rtag=0; 
		}
	}
}
void InThreading(BiTree p)           //��������������������� 
{
	if(p)
	{
		InThreading(p->lchild);  //������������
		if(!p->lchild)           //ǰ������ 
		{
			p->ltag=Thread;      //T��������Ϊ�գ���T����ָ�������� 
			p->lchild=pre;       //T����ָ��ָ������ǰ�� 
		}
		if(!pre->rchild)         //������� 
		{
			pre->rtag=Thread;    //pre����ָ��Ϊ��,pre��ָ��ָ���� 
			pre->rchild=p;       //   ���������� 
		} 
		pre=p;                  //����preָ��T��ǰ��  
		InThreading(p->rchild); //������������
	}
}
void InOrderThreading(BiTree T)            //����������������ڱ����Ĺ������������������������������� 
{
	Thrt=(BiTree)malloc(sizeof(BiTNode));
	Thrt->ltag=Link,Thrt->rtag=Thread;   //��ͷ��㣨��ָ��ָ��������ĸ���㣬��ָ��ָ���������ʱ���ʵ����һ����㣩                     ���������� 
	Thrt->rchild=Thrt;         //��ָ���ָ                  ���������� 
	if(!T)Thrt->lchild=Thrt;   //���������գ�����ָ���ָ 
	else
	{
		Thrt->lchild=T;     //��ָ��ָ��������ĸ���� 
		pre=Thrt;
		InThreading(T);     //��������������������� 
		pre->rchild=Thrt;
		pre->rtag=Thread;    //���һ����������� 
		Thrt->rchild=pre;
	}
} 
void InOrderTraverse_Thr(BiTree T)  //��������������������ǵݹ��㷨�� 
{
	BiTNode *p;
	p=T->lchild;                 //pָ������ 
	while(p!=T)                  //�������������ʱ��p==T 
	{
		while(p->ltag==Link)p=p->lchild;       //�ҵ�������Ϊ�յĽ�� 
		printf("%c ",p->data);
		while(p->rtag==Thread&&p->rchild!=T)   
		{
			p=p->rchild;
			printf("%c ",p->data);   //���ʺ�̽�� 
		}
		p=p->rchild;
	}
} 
int main()
{
	freopen("input.txt","r",stdin);
	BiTree T;     //��������������� 
	create_T(T);  //���������� 
	InOrderThreading(T);  //����������Զ���������������
	InOrderTraverse_Thr(Thrt);  //����������������� 
	return 0;
}
