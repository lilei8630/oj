#include <stdio.h>

struct vocab_word {
  long long cn; //词频,来自于vocab file或者从训练模型中来计算 8B
  int *point;   //Huffman编码对应内节点的路径？？ 8B
  char *word; 	//word：string 字面值     8B
  char *code; 	//code：Huffman编码      8B
  char codelen; //codelen：huffman编码的长度 8B
  int a;
  int b;
};
struct S5 { };  
struct S4{ 
    char a; 
    long b; 
    //static long c; //静态 
}; 
struct student 
{ 
    char name[5]; 
    int num; 
    short score; 
};
struct student2
{ 
    int num; 
    char name[5]; 
    short score; 
};

struct test1 
{ int a; 
	int b[4]; 
};

struct test2 
{ 
	char a; 
	int b; 
	double c; 
	bool d; 
};
struct test3 
{ 
 char a; 
 test2 bb;//见上题 
 int cc; 
};
struct test4 
{ 
	char a; 
	int b; 
}; 
struct test5 
{ char c; 
 test4 d; 
 double e; 
 bool f; 
};
union   mm{    
  char   a;//元长度1    
  int   b[5];//元长度4    
  double   c;//元长度8    
  int   d[3];    
  };   

int main()
{
	printf("struct size: %lu\n",sizeof(vocab_word));
	printf("long long size: %lu\n",sizeof(long long));
	printf("int size: %lu\n",sizeof(int));
	printf("char * size: %lu\n",sizeof(char *));
	printf("char %lu\n",sizeof(char));
	printf("S5 %lu\n",sizeof(S5));
	//静态变量存放在全局数据区内，而sizeof计算栈中分配的空间的大小，故不计算在内，S4的大小为8+8=16。
	printf("S4 %lu\n",sizeof(S4));
	/*
	|char|char|char|char| 
	|char|----|----|----| 
	|--------int--------| 
	|--short--|----|----| 
	*/		
	printf("student %lu\n",sizeof(student));
	/*
	|--------int--------| 
	|char|char|char|char| 
	|char|----|--short--|
	*/ 
	printf("student2 %lu\n",sizeof(student2));
	printf("test1 %lu\n",sizeof(test1));
	printf("test2 %lu\n",sizeof(test2));
	/*
	分析：该结构体有三个成员，其中第二个bb是类型为test2的结构体，长度为24，且该结构体最大长度成员类型为double型，以后成员中没有double型，所以按bb分界为两部分： 
	第一部分有a 、bb两部分，a长度为1，bb长度为24，取8的大于25的最小倍数32； 
	第二部分有cc，长度为4，去8的大于4的最小倍数为8； 
	两部分之和为40，故sizeof(test3)=40;
	*/
	printf("test3 %lu\n",sizeof(test3));
	/*
	分析：test5明显含有结构体test4，按例2容易知道sizeof(test4)=8，且其成员最大长度为4;则结构体test5的最大成员长度为8(double 型)，考试.大提示e是分界点，分test5为两部分： 
	第一部分由c 、d、e组成，长度为1、8、8，故和为17，取8的大于17的最小倍数为24； 
	第二部分由f组成，长度为1，取8的大于1的最小倍数为8， 
	两部分和为32，故sizeof(test5)=24+8=32;
	*/
	printf("test5 %lu\n",sizeof(test5));
	//union的存储空间先看它的成员中哪个占的空间最大,拿他与其他成员的元长度比较,如果可以整除就行
	printf("mm %lu\n",sizeof(mm));
	return 0;
	return 0;
}