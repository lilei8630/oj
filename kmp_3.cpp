#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 100

typedef int Status;
typedef char ElemType;
typedef struct Chunk{
	ElemType ch;
	struct Chunk *next,*pre,*pnext;
}Chunk;
typedef struct{
	struct Chunk *head,*tail;
	int curlen;
}LString;

Status StrAssign(LString &S,char *chars){
	Chunk *p,*q;
	int i;
	if (S.head) free(S.head);
	S.curlen=strlen(chars);
	S.head=(Chunk*)malloc(sizeof(Chunk));
	if (!S.head) return OVERFLOW;
	p=S.head;
	p->pre=(Chunk*)malloc(sizeof(Chunk));
	if (!p->pre) return OVERFLOW;
	p->pre->ch=0;
	p->pre->next=p;
	p->ch=*chars;
	p->next=NULL;
	for (i=1;i<S.curlen;i++){
		chars++;
		q=(Chunk*)malloc(sizeof(Chunk));
		if (!q) return OVERFLOW;
		q->ch=*chars;
		q->next=p->next;
		p->next=q;
		q->pre=p;
	}
}




int index(LString S,LString T){
	Chunk *p,*q;
	int i;
	p=S.head;q=T.head;
	while (!p->next||!q->next){
		if (p->ch==q->ch){p=p->next;q=q->next;}
		else q=q->pnext;
	}
	if (!q->next){
		i=1;
		while (i<T.curlen) p=p->pre,++i;
		i=1;
		while (!p->pre->ch) p=p->pre,++i;
		return i;
	}
	if (!p->next) return 0;
}

Chunk* GetNext(LString T,Chunk *p){
	if (p==T.head) return p->pre;
	if (p->ch==p->pre->pnext->ch) return (p->pre->pnext->next);
	else return GetNext(T,p->pre->pnext);
}


int main(){
	Chunk* p;
	char chars[100],*pch;
	LString S,T;
	int i;
	gets(chars);
	pch=chars;
	S.curlen=strlen(chars);
	StrAssign(S,pch);
	gets(chars);
	pch=chars;
	T.curlen=strlen(chars);
	StrAssign(T,pch);
	p=T.head;
	for (i=0;i<T.curlen;i++) {
		p->pnext=GetNext(T,p);
		p=p->next;
	}
	index(S,T);
}
