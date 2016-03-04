#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;//从小到大
	//return *(int *)b-*(int *)a;//从大到小
}

int main()
{
	int i,a[10];
	for (i = 0; i < 10; ++i)
	{
		scanf("%d",&a[i]);
	}
	printf("before sort:\n");
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	qsort(a,10,sizeof(int),cmp);
	printf("after sort: \n");
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}