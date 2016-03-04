#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int main()
{
	int *p=NULL;
	int i=0;
	//为p从堆上分配SIZE个int型空间
	p=(int *)calloc(SIZE,sizeof(int));
	if(NULL==p)
	{
		printf("Error in calloc.\n");
		return -1;
	}
	//为p指向的SIZE个int型空间赋值
	for(i=0;i<SIZE;i++)
	p[i]=i;
	//输出各个空间的值
	for(i=0;i<SIZE;i++)
		printf("p[%d]=%d\n",i,p[i]);
	free(p);
	p=NULL;
	return 0;

}