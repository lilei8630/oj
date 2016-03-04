#include <stdio.h>
#include <stdlib.h>

int main(){
	freopen("0input.txt","r",stdin);
	unsigned long long m,n;
	unsigned long long count;
	bool flag;
	int pos;
	unsigned long long min;
	while(scanf("%llu %llu",&m,&n)!=EOF){
		flag = false;
		
		unsigned long long *  arr = (unsigned long long * )malloc((m+1)*sizeof(unsigned long long));
		for (int i = 1; i <=m; ++i) scanf("%llu",&arr[i]);

		min = arr[1];
		
		for (int i = 2; i <=m; ++i)
			if (arr[i]<min)
				min=arr[i];
		for (int i = 1; i <= m; ++i)
		{
			arr[i]-=min;
		}
		count = m * min;
		
		
		while(!flag){
			if (arr[n]==0)
			{
				flag = true;
				pos = n;
				break;
			}
			arr[n--]--;
			count++;
			if (arr[n]==0)
			{
				flag = true;
				pos = n;
				break;
			}
			if (n==0)
			{
				n=m;
			}
		}
		arr[pos] = count;
		for (int i = 1; i <= m; ++i)
			printf("%llu ", arr[i]);
		printf("\n");		
		free(arr);
	}
	return 0;
}