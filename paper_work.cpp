#include <stdio.h>

int n;

int arr[100];

int arr_data[200];

int neg_num;

int num;

int k;

int main(){
	freopen("input.txt","r",stdin);

	while(scanf("%d",&n)!=EOF){
		neg_num=0;

		num=0;

		k=0;

		for (int i = 0; i < n; ++i)
			scanf("%d",&arr_data[i]);

		for (int i = 0; i < n; ++i){
			if (arr_data[i]>=0)
				num++;
			else{ 
				if (neg_num<=1)
				{
					num++;
					neg_num++;
				}else{
					arr[k++]=num;
					neg_num=1;
					num=1;

				}
			}
			if (i==n-1)
				arr[k++]=num;
			//printf("arr_data[%d]=%d num=%d neg_num=%d k=%d\n",i,arr_data[i],num,neg_num,k);	
		}

		printf("%d\n",k);
		for (int i = 0; i < k; ++i)
			printf("%d ", arr[i]);
		printf("\n");
		
	}


	return 0;
}