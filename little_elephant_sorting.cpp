#include <stdio.h>
#include <string.h>
int array[100010];
int main(){
	freopen("input.txt","r",stdin);
	int n;
	long long ans;
	while(scanf("%d",&n)!=EOF){
		ans=0;
		memset(array,0,sizeof(array));
		for (int i = 0; i < n; ++i) scanf("%d",&array[i]);
		//for (int i = 0; i < n; ++i) printf("%d ",array[i] );


		for (int i = 1; i < n; ++i)
		{

			if (array[i]<array[i-1])
				ans+=array[i-1]-array[i];
			
		}
		printf("%lld\n",ans);
		
	}
	return 0;

}
