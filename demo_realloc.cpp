#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *p = NULL;
	p=(int *) malloc(sizeof(int));
	*p=3;
	printf("p=%p\n",p);
	printf("*p=%d\n",*p);
	p=(int *)realloc(p,sizeof(int));
	printf("p=%p\n",p);
	printf("*p=%d\n",*p);

	p=(int *)realloc(p,3*sizeof(int));
	printf("p=%p\n",p);
	printf("*p=%d\n",*p);
	//释放p指向的空间
	realloc(p,0);
	p=NULL;
	return 0;
}