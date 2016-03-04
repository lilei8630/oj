#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int cmp(const void * a,const void *b)
{
	return *(int *)b-*(int *)a;
}
/*
模仿word2vec里创建Huffman树的方法
*/
int main()
{
	freopen("input.txt","r",stdin);
	int n;
	int * array;
	int pos1,pos2,a;
	int min1_index,min2_index;
	while(scanf("%d",&n)!=EOF){
		//printf("%d \n",n );
		array =(int *) malloc((2*n-1)*sizeof(int));
		for (int i = 0; i < n; ++i)
			scanf("%d",array+i);
		qsort(array,n,sizeof(int),cmp);
		for (int i = n; i < 2*n-1; ++i)
			array[i]=1000;
		//for (int i = 0; i < 2*n-1; ++i)	printf("%d ",array[i]);
		pos1 = n-1;
		pos2 = n;
		for (a = 0; a < n-1; ++a)
		{
			if(pos1>=0){
				if (array[pos1]<array[pos2])
				{
					min1_index=pos1;
					pos1--;
				}else{
					min1_index=pos2;
					pos2++;
				}

			}else{
				min1_index=pos2;
				pos2++;

			}
			if(pos1>=0){
				if (array[pos1]<array[pos2])
				{
					min2_index=pos1;
					pos1--;
				}else{
					min2_index=pos2;
					pos2++;
				}

			}else{
				min2_index=pos2;
				pos2++;
			}
			array[n+a]=array[min1_index]+array[min2_index];			
		}
		int sum=0;
		for (int i = n; i < 2*n-1; ++i)
			sum+=array[i];
		printf("%d\n", sum);
		

	}
}