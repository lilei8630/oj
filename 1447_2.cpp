#include <stdio.h>
#include <vector>
using namespace std;
struct E{ //临接链表中链表元素结构体
	int next;
	int c;
};

vector<E> edge[101];

bool mark[101];

int Dis[101];

int main()
{
	freopen("input.txt","r",stdin);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0&&m==0) break;

		for (int i = 1; i <= n; ++i)
			edge[i].clear();
		while(m--){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			E tmp;
			tmp.c=c;
			tmp.next=b;
			edge[a].push_back(tmp);
			tmp.next=a;
			edge[b].push_back(tmp);
		}
		for (int i = 1; i <=n; ++i)
		{
			Dis[i]=-1;
			mark[i]=false;
		}

		Dis[1]=0;
		mark[1]=true;
		int newp=1;
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < edge[newp].size(); ++j)
			{
				int t = edge[newp][j].next;
				int c = edge[newp][j].c;
				if (mark[t]==true) continue;
				if (Dis[t]==-1||Dis[t]>Dis[newp]+c)
					Dis[t]=Dis[newp]+c;								
			}
		
		int min = 123123123;
		for (int j = 1; j <=n; ++j)
		{
			if (mark[j]==true)
				continue;
			if (Dis[j]==-1)
				continue;
			if (Dis[j]<min)
			{
				min=Dis[j];
				newp=j;
			}
		}
			mark[newp]=true;	
		}
		printf("%d\n",Dis[n]);
		
	}
	return 0;
}
