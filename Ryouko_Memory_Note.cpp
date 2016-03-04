#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#define LL long long
#define pb push_back
const int maxn = 1e5 + 5;
using namespace std;
vector<int> adj[maxn];  // adj[i]: 数值为i的数中相邻的两个不等于i的数
LL sum, ans;      		// sum: 每个数相邻数之差的总和;   ans:最后答案
LL adjsum[maxn], adjminsum[maxn];   // adjsum[i]：数值为i的数相邻之间的差 adjminsum[i]: 数值为i的数相邻之间的差的最小值
int a[maxn];    		// 原始序列

int main()
{
	freopen("0input.txt","r",stdin);
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (int i = 1; i <= m; i++)
			scanf("%d", a+i);
		for (int i = 1; i <= m; i++)
		{
			if (i != 1 && a[i-1] != a[i])
				adj[a[i]].pb(a[i-1]);
			if (i != m && a[i+1] != a[i])
				adj[a[i]].pb(a[i+1]);
		}
		//test
		for (int i = 1; i <=n; ++i)
		{
			if (adj[i].size())
			{
				printf("%d: ",i );
				for (int j = 0; j <adj[i].size(); ++j)
				{

					printf("%d ",adj[i][j]);
				}
				printf("\n");
			}
		}
		sum = 0;
		memset(adjsum, 0, sizeof(adjsum));
		for (int i = 1; i <= n; i++)
		{
			if (adj[i].size())
			{
				sort(adj[i].begin(), adj[i].end());   // 排序以便找出中位数
				for (int j = 0; j < adj[i].size(); j++){
					adjsum[i] += (i >= adj[i][j] ? i-adj[i][j] : adj[i][j]-i);
				}
				printf("adjsum[%d]=%lld\n",i,adjsum[i]);
				sum += adjsum[i];
			}
		}
		sum /= 2;   // 由于每个数相邻数之差的总和算了两遍，除以2刚好只算了一次
		ans = sum;
		memset(adjminsum, 0, sizeof(adjminsum));
		for (int i = 1; i <= n; i++)
		{
			if (adj[i].size())
			{
				int mid = adj[i].size() / 2;
				for (int j = 0; j < adj[i].size(); j++)
					adjminsum[i] += (adj[i][mid] >= adj[i][j] ? adj[i][mid]-adj[i][j] : adj[i][j]-adj[i][mid]);
				printf("adjminsum[%d]=%lld\n",i,adjminsum[i]);
				ans = min(ans, sum-adjsum[i]+adjminsum[i]);
			}
		}
		printf("%lld\n", ans);
		for (int i = 1; i <= n; i++)     // 清空
			adj[i].clear();
	}
	return 0;
}
