#include <cstdio>
#include <cstring>
#define INF 0x7FFFFFFF
const int MAX =101;
const int DIS = 4000;
const int OFFSET =2000;
int w[MAX];
int dp[MAX+1][DIS+1];

void init()
{
	memset(w,0,sizeof(w));
	for (int i = 0; i < DIS+1; ++i)
	{
		dp[0][i]=-INF;
	}
	dp[0][OFFSET] = 0;
}
int FindMax(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int t;
	while(scanf("%d",&t)!=EOF){
		for (int k = 0; k < t; ++k)
		{
			bool hasZero = false;
			init();
			int n;
			scanf("%d",&n);

			int cnt=0;
			for (int i = 0; i < n; ++i)
			{
				scanf("%d",&w[++cnt]);
				if (w[cnt]==0)
				{
					hasZero=true;
					cnt--;
				}
			}
			n=cnt;
			for (int i = 1; i <=n; ++i)
			{
				for (int j = 0; j <= DIS; ++j)
				{
					dp[i][j]=FindMax(dp[i-1][j],
						FindMax(dp[i-1][j-w[i]]+w[i],
							dp[i-1][j+w[i]]+w[i]));
				}
			}
			printf("Case %d: ",k+1);
			if (dp[n][OFFSET]==0)
			{
				puts(hasZero==true?"0":"-1");
			}
			else
				printf("%d\n",dp[n][OFFSET]/2);
		}
	}
	return 0;
}