/*�������������ݹ�ͷǵݹ飩*/ 
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define STACK_SIZE 100
typedef struct BiTNode               //������ÿ�����ṹ 
{
	char data;
	struct BiTNode *lchild,*rchild;  //���Һ���ָ�� 
}BiTNode,*BiTree;
BiTNode *s[MAX]={NULL};

void create_T(BiTree &T)              //����������������һ������������������ֵ 
{
	BiTNode *q;
	int i;
	char x=' ';
	printf("������ֵ:\n");
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
			if(i%2==0)s[i/2]->lchild=q;        //��˫�׽�����ϵ 
			else s[i/2]->rchild=q; 
		}
	}
}
void Pre(BiTree T)                      //����������������ǵݹ��㷨�� 
{
	BiTNode *stack[STACK_SIZE],*p;
	int top=-1;
	if(T)
	{
		top++;
		stack[top]=T;      //�������ջ
		while(top>-1)      //ջ����ʱѭ�� 
		{
			p=stack[top];
			top--;
			printf("%c ",p->data);  //��ӡ���������׽��
			if(p->rchild)           //�Һ�����ջ 
			{
				top++;
				stack[top]=p->rchild;
			}
			if(p->lchild)           //������ջ 
			{
				top++;
				stack[top]=p->lchild;
			} 
		} 
		printf("\n"); 
	}
}
void PreOrderTraverse(BiTree T)   //����������������ݹ���ã� 
{
	if(T)
	{
		printf("%c ",T->data);
		if(T->lchild)PreOrderTraverse(T->lchild);	
		if(T->rchild)PreOrderTraverse(T->rchild);
	}
} 
void In(BiTree T)               //����������������ǵݹ��㷨�� 
{
	BiTNode *stack[STACK_SIZE],*p;
	int top=-1;
	if(T)
	{
		p=T;
		while(p||top>-1)      
		{
			while(p)           //ɨ�����е����ӣ�������ջ�� 
			{
				top++;
				stack[top]=p;
				p=p->lchild;
			}
			if(top>-1)
			{
				p=stack[top];   //p�ص�û�����ӵĸ��׽�㴦 
				printf("%c ",p->data);  //��ӡ���׽��
				top--;           //??????  
				p=p->rchild;
			}
		} 
		printf("\n"); 
	}
} 
void InOrderTraverse(BiTree T)  //����������������ݹ���ã� 
{
	if(T)
	{
		if(T->lchild)InOrderTraverse(T->lchild);
		printf("%c ",T->data);
		if(T->rchild)InOrderTraverse(T->rchild);
	}
}
void Post(BiTree T)              //����������������ǵݹ��㷨�� 
{
	int sign=0;
	BiTNode *stack[STACK_SIZE],*p;
	int top=-1;
	if(T)
	{
		do
		{
			while(T)
			{
				top++;
				stack[top]=p;
				T=T->lchild;
			}
			p=NULL;
			sign=1;
			while(top>-1&&sign)
			{
				T=stack[top];
				if(T->rchild==p)
				{
					printf("%c ",T->data);
					top--;
					p=T;
				}
				else
				{
					T=T->rchild;
					sign=0;
				}
			}
		}
		while(top>-1);
		printf("\n"); 
	}
}
void PostOrderTraverse(BiTree T)  //����������������ݹ���ã� (������)
{
	if(T)
	{
		if(T->lchild)InOrderTraverse(T->lchild);
		if(T->rchild)InOrderTraverse(T->rchild);
		printf("%c ",T->data);
	}
}
int main()
{
	BiTree T;     //��������������� 
	create_T(T);
	printf("\n�������������  �ǵݹ��㷨:\n");
	Pre(T);
	printf("\n�������������  �ݹ��㷨:\n");
	PreOrderTraverse(T);
	printf("\n�������������  �ǵݹ��㷨:\n");
	In(T);
	printf("\n�������������  �ݹ��㷨:\n");
	InOrderTraverse(T);
	printf("\n�������������  �ǵݹ��㷨:\n");
	Post(T);
	printf("\n�������������  �ݹ��㷨:\n");
	PostOrderTraverse(T);
	return 0; 
}

