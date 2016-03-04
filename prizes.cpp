#include <stdio.h>
#include <string.h>
typedef unsigned long long LL;
int n;
int points[60];
int cost[5];
LL cnt[5];
LL sum;
int main(){
	freopen("input.txt","r",stdin);

	while(scanf("%d",&n)!=EOF){
		memset(points,0,sizeof(points));
		memset(cost,0,sizeof(cost));
		memset(cnt,0,sizeof(cnt));
		sum=0;
		for (int i = 0; i < n; ++i){
			scanf("%d",&points[i]);
		}
		for (int i = 0; i < 5; ++i)
			scanf("%d",&cost[i]);

		for (int i = 0; i < n; ++i)
		{
			sum+=points[i];
			while(sum>=cost[0]){
				for (int j = 4; j >= 0; --j)
				{
					int num = sum/cost[j];
					if (num>=1)
					{
						cnt[j]+=num;
						sum-=cost[j]*num;
						break;
					}
				}
			}
		}
		printf("%llu %llu %llu %llu %llu\n",cnt[0],cnt[1],cnt[2],cnt[3],cnt[4]);
		printf("%llu\n",sum);
	}
}