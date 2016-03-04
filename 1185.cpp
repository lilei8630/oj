#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[1005];
int compare(const void *a, const void *b) {
        return *(int *)a - *(int *)b; 
}
int main(){
	freopen("input.txt","r",stdin);
	int n;
	int tmp;
	while(scanf("%d",&n)!=EOF){
		memset(arr,0,sizeof(arr));
		if(n==1){
			scanf("%d",&tmp);
			printf("%d\n",tmp);
			printf("-1\n");
		}else{
			for (int i = 0; i < n; ++i) scanf("%d",&arr[i]);
			qsort(arr, n, sizeof(int), compare);
			printf("%d\n",arr[n-1] );
			for (int i = 0; i < n-1; ++i)
			{
				if(i==n-2)
					printf("%d\n", arr[n-2]);
				else
				 	printf("%d ",arr[i]);
			}
			

			
		}

	}
	return 0;

}