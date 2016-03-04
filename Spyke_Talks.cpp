#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int arr[1005];
int flag_0,flag_1;
int compare(const void *a, const void *b) {
        return *(int *)a - *(int *)b; 
}
int main(){
	freopen("0input.txt","r",stdin);
	int n,start,cnt;
	while(scanf("%d",&n)!=EOF){
		for (int i = 0; i < n; ++i)
			scanf("%d",&arr[i]);
		qsort(arr, n, sizeof(int), compare);
		//找出第一个非零的
		int ii;
		flag_1=flag_0=0;
		for (ii = 0; ii < n; ++ii)
		{
			if (arr[ii]!=0){
				start=ii;
				break;
			}
		}

		if (ii==n)
		{
			flag_0=1;
		}
		cnt=0;
		
		for (int i = start; i < n; ++i){
			if (arr[i]==arr[i+1])
			{
				if (arr[i+1]==arr[i+2])
				{
					flag_1=1;
					break;
				}else{
					cnt++;
					i+=1;
				}
			}
			
		}
		if (flag_0)
		{
			printf("0\n");
		}else if(flag_1){
			printf("-1\n");
		}else{
			printf("%d\n",cnt );
		}
		

	}
	return 0;





}