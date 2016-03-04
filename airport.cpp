#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n,m;
int array[1010];
int array_max[1010];
int array_min[1010];
int max,min;
int cmp_max(const void * a,const void * b){
	return *(int *)b-*(int *)a;
}
int cmp_min(const void * a,const void * b){
	return *(int *)a-*(int *)b;
}
int main(){
	freopen("input.txt","r",stdin);

	while(scanf("%d%d",&n,&m)!=EOF){
		memset(array,0,sizeof(array));
		memset(array_max,0,sizeof(array_max));
		memset(array_min,0,sizeof(array_min));

		max=0;
		min=0;
		for (int i = 0; i < m; ++i) {
			scanf("%d",&array[i]);
			array_max[i]=array_min[i]=array[i];
		}
		//find max
		qsort(array_max,m,sizeof(int),cmp_max);
		for (int i = 0; i < n; ++i)
		{
			max+=array_max[0];
			array_max[0]--;
			qsort(array_max,m,sizeof(int),cmp_max);
		}
		//printf("max:%d\n",max);
		//find min

		qsort(array_min,m,sizeof(int),cmp_min);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (array_min[j]>0)
				{
					min+=array_min[j];
					array_min[j]--;
					qsort(array_min,m,sizeof(int),cmp_min);
					break;
				}
			}
		}
		//printf("min:%d\n",min);
		printf("%d %d\n",max,min );

	}
	return 0;
}