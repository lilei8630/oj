/*线索二叉树（指向结点前驱和后继的指针为线索）*/ 
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define Link 0     //左右孩子 
#define Thread 1   //前驱和后继（线索） 
typedef struct BiTNode               //二叉树每个结点结构 
{
	char data;
	int ltag,rtag;              
	struct BiTNode *lchild,*rchild;  //左右孩子指针 
}BiTNode,*BiTree;
BiTNode *s[MAX]={NULL};
BiTNode *Thrt,*pre;
void create_T(BiTree &T)   //构建二叉树，按照一定次序输入二叉树结点值 
{
	BiTNode *q;
	int i;
	char x=' ';
	//printf("输入结点值:\n");
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
			if(i%2==0)s[i/2]->lchild=q,s[i/2]->ltag=0;  //与双亲建立联系 
			else s[i/2]->rchild=q,s[i/2]->rtag=0; 
		}
	}
}
void InThreading(BiTree p)           //中序遍历进行中序线索化 
{
	if(p)
	{
		InThreading(p->lchild);  //左子树线索化
		if(!p->lchild)           //前驱线索 
		{
			p->ltag=Thread;      //T的左子树为空，则T的左指针是线索 
			p->lchild=pre;       //T的左指针指向它的前驱 
		}
		if(!pre->rchild)         //后继线索 
		{
			pre->rtag=Thread;    //pre的右指针为空,pre右指针指向后继 
			pre->rchild=p;       //   ？？？？？ 
		} 
		pre=p;                  //保持pre指向T的前驱  
		InThreading(p->rchild); //右子树线索化
	}
}
void InOrderThreading(BiTree T)            //中序遍历二叉树（在遍历的过程中线索化）（二叉树的线索链表） 
{
	Thrt=(BiTree)malloc(sizeof(BiTNode));
	Thrt->ltag=Link,Thrt->rtag=Thread;   //建头结点（左指针指向二叉树的根结点，右指针指向中序遍历时访问的最后一个结点）                     ？？？？？ 
	Thrt->rchild=Thrt;         //右指针回指                  ？？？？？ 
	if(!T)Thrt->lchild=Thrt;   //若二叉树空，则左指针回指 
	else
	{
		Thrt->lchild=T;     //左指针指向二叉树的根结点 
		pre=Thrt;
		InThreading(T);     //中序遍历进行中序线索化 
		pre->rchild=Thrt;
		pre->rtag=Thread;    //最后一个结点线索化 
		Thrt->rchild=pre;
	}
} 
void InOrderTraverse_Thr(BiTree T)  //中序遍历线索二叉树（非递归算法） 
{
	BiTNode *p;
	p=T->lchild;                 //p指向根结点 
	while(p!=T)                  //空树或遍历结束时，p==T 
	{
		while(p->ltag==Link)p=p->lchild;       //找到左子树为空的结点 
		printf("%c ",p->data);
		while(p->rtag==Thread&&p->rchild!=T)   
		{
			p=p->rchild;
			printf("%c ",p->data);   //访问后继结点 
		}
		p=p->rchild;
	}
} 
int main()
{
	freopen("input.txt","r",stdin);
	BiTree T;     //创立二叉树根结点 
	create_T(T);  //构建二叉树 
	InOrderThreading(T);  //用中序遍历对二叉树进行线索化
	InOrderTraverse_Thr(Thrt);  //中序遍历二叉线索树 
	return 0;
}
