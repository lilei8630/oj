#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 100

typedef int Status;
typedef char ElemType;
typedef struct {
	ElemType *top;
	ElemType *base;
	int stacksize;
}SqStack;

Status InitStack(SqStack &S){
	S.base=(ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if (!S.base) return OVERFLOW;
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
}

int StackLength(SqStack S){
	return S.top-S.base;
}

Status GetTop(SqStack S,ElemType &e){
	if (StackLength(S)==0) return ERROR;
	e=*(S.top-1);
	return OK;
}

Status Push(SqStack &S,ElemType e){
	if (StackLength(S)+1>S.stacksize) return OVERFLOW;
	*S.top=e;
	S.top++;
	return OK;
}

Status Pop(SqStack &S,ElemType &e){
	if (StackLength(S)==0) return ERROR;
	S.top--;
	e=*S.top;
	return OK;
}

int charpior(ElemType e){
	if (e=='*'||e=='/') return 2;
	if (e=='+'||e=='-') return 1;
	return 3;
}

Status Sort(SqStack &S,ElemType* p,int n){
	ElemType *p1,*p2,*p0;
	ElemType top;
	Status s;
	int l,SL;
	
	p--;
	p2=p0=p+n;
	while (p<=p0){
		p++;
		if (*p=='('){
			p1=p+1;
			while(*p2!=')') p2--;
			p=p2;
			l=p2-p1;
			SL=StackLength(S);
			S.base=S.top;
			Sort(S,p1,l);
			S.base-=SL;
		}
		if (charpior(*p)==3) {putchar(*p);continue;}
		s=GetTop(S,top);
		if (s==ERROR) {Push(S,*p);continue;}
		if (charpior(top)>=charpior(*p)){Pop(S,top);putchar(top);Push(S,*p);}
		else Push(S,*p);
	}
	while (StackLength(S)!=0) {Pop(S,top);putchar(top);}
	return OK;
}

int main(){
	ElemType equ[STACK_INIT_SIZE];
	int i,n;
	ElemType* p;
	SqStack S;
	
	InitStack(S);
	gets(equ);
	n=strlen(equ);
	p=equ;
	
	Sort(S,p,n);
	
	return 0;
}
