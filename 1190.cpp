#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Num
{
	char str[1010];
	int len;
}Num;

int cmp(const void *,const void *);

int main()
{
	freopen("input.txt","r",stdin);
	int N;
	Num Data[101];
	while(scanf("%d",&N)!=EOF)
	{
		for (int i = 0; i < N; ++i)
		{
			scanf("%s",Data[i].str);
			Data[i].len=strlen(Data[i].str);

		}
		qsort(Data,N,sizeof(struct Num),cmp);
		for (int i = 0; i < N; ++i)
			printf("%s\n",Data[i].str);
	}
	return 0;

}
int cmp(const void * a,const void * b)
{
	struct Num *cm1 =(struct Num *)a;
	struct Num *cm2 =(struct Num *)b;
	if (cm1->len!=cm2->len)
		return cm1->len-cm2->len;

	return strcmp(cm1->str,cm2->str);


}