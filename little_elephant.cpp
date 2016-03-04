#include <stdio.h>
#include <stdlib.h>
int cmp(const void * a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main(){
	freopen("input.txt","r",stdin);
	int n;
	int *array;
	int *original;
	bool flag;
	int index;
	while(scanf("%d",&n)!=EOF){
		flag=true;
		array=(int *)malloc(n*sizeof(int));
		original=(int *)malloc(n*sizeof(int));
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",array+i);
			original[i]=array[i];
			
		}
		qsort(array,n,sizeof(int),cmp);
		
		//for (int i = 0; i < n; ++i) printf("%d ", array[i]);
		
		if (array[0]==array[1])
		{
			flag=false;
		}else{
			for (int i = 0; i < n; ++i)
			{
				if (original[i]==array[0]){
					index=i+1;
					break;
				}
			}

		}
		if (flag)
		{
			printf("%d\n",index);
		}else
			printf("Still Rozdil\n");
		



	}
}