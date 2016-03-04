/*遍历二叉树（递归和非递归）*/ 
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define STACK_SIZE 100
typedef struct BiTNode               //二叉树每个结点结构 
{
	char data;
	struct BiTNode *lchild,*rchild;  //左右孩子指针 
}BiTNode,*BiTree;
BiTNode *s[MAX]={NULL};

void create_T(BiTree &T)              //构建二叉树，按照一定次序输入二叉树结点值 
{
	BiTNode *q;
	int i;
	char x=' ';
	printf("输入结点值:\n");
	while(x!='$')                 //结束输入标志x='$' 
	{
		scanf("%d %c",&i,&x); 
		if(x=='$')break;          
		q=(BiTNode *)malloc(sizeof(BiTNode));   //建立新结点 
		q->data=x,q->lchild=NULL,q->rchild=NULL;
		s[i]=q;         //新结点地址存入指针数组中
		if(i==1)T=q;    //设i=1对应的结点是根结点
		else        
		{
			if(i%2==0)s[i/2]->lchild=q;        //与双亲建立联系 
			else s[i/2]->rchild=q; 
		}
	}
}
void Pre(BiTree T)                      //先序遍历二叉树（非递归算法） 
{
	BiTNode *stack[STACK_SIZE],*p;
	int top=-1;
	if(T)
	{
		top++;
		stack[top]=T;      //根结点入栈
		while(top>-1)      //栈不空时循环 
		{
			p=stack[top];
			top--;
			printf("%c ",p->data);  //打印二叉树父亲结点
			if(p->rchild)           //右孩子入栈 
			{
				top++;
				stack[top]=p->rchild;
			}
			if(p->lchild)           //左孩子入栈 
			{
				top++;
				stack[top]=p->lchild;
			} 
		} 
		printf("\n"); 
	}
}
void PreOrderTraverse(BiTree T)   //先序遍历二叉树（递归调用） 
{
	if(T)
	{
		printf("%c ",T->data);
		if(T->lchild)PreOrderTraverse(T->lchild);	
		if(T->rchild)PreOrderTraverse(T->rchild);
	}
} 
void In(BiTree T)               //中序遍历二叉树（非递归算法） 
{
	BiTNode *stack[STACK_SIZE],*p;
	int top=-1;
	if(T)
	{
		p=T;
		while(p||top>-1)      
		{
			while(p)           //扫描所有的左孩子，并存入栈中 
			{
				top++;
				stack[top]=p;
				p=p->lchild;
			}
			if(top>-1)
			{
				p=stack[top];   //p回到没有左孩子的父亲结点处 
				printf("%c ",p->data);  //打印父亲结点
				top--;           //??????  
				p=p->rchild;
			}
		} 
		printf("\n"); 
	}
} 
void InOrderTraverse(BiTree T)  //中序遍历二叉树（递归调用） 
{
	if(T)
	{
		if(T->lchild)InOrderTraverse(T->lchild);
		printf("%c ",T->data);
		if(T->rchild)InOrderTraverse(T->rchild);
	}
}
void Post(BiTree T)              //后序遍历二叉树（非递归算法） 
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
void PostOrderTraverse(BiTree T)  //后序遍历二叉树（递归调用） (有问题)
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
	BiTree T;     //创立二叉树根结点 
	create_T(T);
	printf("\n先序遍历二叉树  非递归算法:\n");
	Pre(T);
	printf("\n先序遍历二叉树  递归算法:\n");
	PreOrderTraverse(T);
	printf("\n中序遍历二叉树  非递归算法:\n");
	In(T);
	printf("\n中序遍历二叉树  递归算法:\n");
	InOrderTraverse(T);
	printf("\n后序遍历二叉树  非递归算法:\n");
	Post(T);
	printf("\n后序遍历二叉树  递归算法:\n");
	PostOrderTraverse(T);
	return 0; 
}

