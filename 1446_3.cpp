#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#define N 1010

typedef struct node{  
    char name[4];  //人名  
    int time;      //通话时间  
    int father;    //父节点  
}Node;  

typedef struct head{  
    char name[4];  //头领姓名  
    int num;       //人数  
}Head;  

Node people[N];  
Head gang[N];   //头领  
int num;           //总人数  

void init(){
	Node node;
	for (int i = 0; i < N; ++i)
	{
		node.name="zzz";
		node.time=0;
		node.father=-1;		
	}
}

int FindSet(Node node){
	if (node.father==-1)
}