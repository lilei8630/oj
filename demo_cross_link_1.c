#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef int Status;

typedef struct OLNode{
	int i,j;
	ElemType e;
	struct OLNode *right,*down;
}OLNode , *OLink;

typedef struct{
	OLink *rhead,*chead;
	int mu, nu ,tu ;
}CrossLink;

Status CreateSMatrix_OL(CrossLink * M){
	
	scanf("%d%d%d",&M->mu,&M->nu,&M->tu);
	
	M->rhead = (OLink *)malloc((M->mu+1)*sizeof(OLink));
	M->chead = (OLink *)malloc((M->nu+1)*sizeof(OLink));
	
	//������ʼ��ָ������ʹ��ȫָ��NULL���� 
	int count;
	for(count=1;count<=M.nu;count++)
	   M.rhead[count] = NULL;
	for(count=1;count<=M.mu;count++)
	   M.chead[count] = NULL;
	//==============��ɳ�ʼ��===========//
	
	//��������Ԫ�أ�
	int i,j,e;OLink temp,p,q;
	for(count=1;count<=M.tu;count++)
	{
		scanf("%d%d%d",&i,&j,&e);
		temp = (OLink)malloc(sizeof(OLNode));
		temp->i=i;temp->j=j;temp->e=e;
		
		//�������е��ʵ�λ�� 
		if(!M.rhead[i]) {
		M.rhead[i]=temp;M.rhead[i]->right=NULL;}
		
		else{
			p=M.rhead[i];q=p->right;
			
			if(p->j > j) {
				M.rhead[i]=temp;M.rhead[i]->right=p;
			}
			
			else{
				    while(q->j < j && q!=NULL)
				    q = q->right;
				p->right=temp;p->right->right=q;
			}
		}
		//�������е��ʵ�λ�� 
			if(!M.chead[j]) {
		M.chead[j]=temp;M.chead[j]->down=NULL;}
		
		else{
			p=M.chead[j];q=p->down;
			
			if(p->i > i) {
				M.chead[j]=temp;M.chead[j]->down=p;
			}
			
			else{
				    while(q->i < i && q!=NULL)
				    q = q-> down ;
				p->down=temp;p->down->down=q;
			}
		}
	}
	return 0; 
} 

Status Tra_SMatrix_OL(CrossLink M)
{
	int i;OLink q;
	for(i=1;i<=M.mu;i++)
	  {
	  	printf("��%d��",i);
	  	q = M.rhead[i];
	  	while(q!=NULL)
	  	{
		  printf("%d  %d  %d\n",q->i,q->j,q->e);
		  q=q->right;
		  }
		printf("\n"); 
	  }
  return 0;
} 

int main()
{
	CrossLink M;
	CreateSMatrix_OL(M);
	Tra_SMatrix_OL(M);
	
	return 0;
}









