#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool line[205][205];
int link[205];
bool vis[205];
int m,n;
bool find(int k){
	int i,j;
	for (int i = 1; i <= n; ++i) //遍历每一个妹子
	{
		if (line[k][i]&&!vis[i])
		{
			vis[i]=true;
			if(link[i]==0||find(link[i])){
				link[i]=k;
				return true;

			}

		}
	}
	return false;

}

int main(){
	freopen("0input.txt","r",stdin);
	int t,p,ans;
	while(scanf("%d%d",&m,&n)!=EOF){
		memset(line,0,sizeof(line));
		memset(link,0,sizeof(link));
		for (int i = 1; i <= m; ++i)
		{
			scanf("%d",&t);
			for (int j = 0; j < t; ++j)
			{

				scanf("%d",&p);
				line[i][p]=true;
			}

		}
		ans =0;
		for (int i = 1; i <= m; ++i)
		{
			memset(vis,0,sizeof(vis));
			if (find(i))
				ans++;
		}

	}
	return 0;
}