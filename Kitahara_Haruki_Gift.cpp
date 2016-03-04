#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
规律:当100的个数为奇数时 或者
    100的个数为0，200的个数为偶数时，不可以均分，其余情况均可以
*/
int arr[105];
int num100,num200,n;
int main(){

	freopen("0input.txt","r",stdin);
	while(scanf("%d",&n)!=EOF){
		memset(arr,0,sizeof(arr));
		num100=num200=0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&arr[i]);
			if (arr[i]==100)
				num100++;
			else
				num200++;
		}
		if (num100%2==1||(num100==0&&num200%2==1))
			printf("NO\n");
		else
			printf("YES\n");
		

	}

	return 0;
}