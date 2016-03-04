#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int * p=NULL;
	p=(int *)malloc(sizeof(int));
	if (NULL==p)
	{
		printf("Can't get memory!\n");
		return -1;
	}
	//输出分配空间上的值
	printf("%d\n",*p);
	//将p指向的空间清0
	memset(p,0,sizeof(int));
	//输出调用memset函数后的结果
	printf("%d\n",*p);
	*p=2;
	printf("%d\n",*p);
	free(p);
	//此时p是野指针，需要将其置为NULL
	p=NULL;
	return 0;
}