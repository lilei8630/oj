#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2147483647 //2^31-1

int n;
int * array;
int min1,min2; //最小值和次小值的指针
int pos1,pos2; //扫描指针
int a;
int cmp(const void * a,const void * b){
	return *(int *)b-*(int *)a;
}

int main(){
	
	
	freopen("input.txt","r",stdin);
	while(scanf("%d",&n)!=EOF&&n){
		array = (int *)malloc((2*n-1)*sizeof(int));
		for (int i = 0; i < n; ++i)
			scanf("%d",array+i);
		for (int i = n; i < 2*n-1; ++i)
			array[i]=MAX;
		qsort(array,n,sizeof(int),cmp);
		//for (int i = 0; i < 2*n-1; ++i) printf("%d ",array[i]);
		pos1=n-1;
		pos2=n;
		for (a = 0; a < n-1; ++a)
		{
			if (pos1>=0) //find min1
			{
				if (array[pos1]<array[pos2])
				{
					min1=pos1;
					pos1--;
				}else{
					min1 = pos2;
					pos2++;
				}
				
			}else{
				min1=pos2;
				pos2++;
			}

			if (pos1>=0) //find min2
			{
				if (array[pos1]<array[pos2])
				{
					min2=pos1;
					pos1--;
				}else{
					min2 = pos2;
					pos2++;
				}
				
			}else{
				min2=pos2;
				pos2++;
			}
			array[n+a]=array[min1]+array[min2];	
		}
		int sum=0;
		for (int i = n; i < 2*n-1; ++i)
		{
			sum+=array[i];
		}
		printf("%d\n",sum);



	}
	



}