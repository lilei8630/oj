#include <stdio.h>
#include <vector>
using namespace std;
struct E
{
	int next;
	int c;
	int cost;
};
vector<E> edge[1001];
int Dis[1001];
int cost[1001];
bool mark[1001];

int main(){
	freopen("input.txt","r",stdin);
	int n,m;
	int S,T; //start,end
	while(scanf("%d%d",&n,&m)!=EOF){
		if (n==0&&m==0) break;
		for (int i = 1; i <=n; ++i)
			edge[i].clear();
		while(m--){
			int a,b,c,cost;
			scanf("%d%d%d%d",&a,&b,&c,&cost);
			E tmp;
			tmp.c=c;
			tmp.cost=cost;
			tmp.next=b;
			edge[a].push_back(tmp);
			tmp.next=a;
			edge[b].push_back(tmp);
		}
		scanf("%d%d",&S,&T);
		for (int i = 1; i <= n; ++i)
		{
			Dis[i]=-1;
			mark[i]=false;
		}
		Dis[S]=0;
		mark[S]=true;
		int newp=S;
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < edge[newp].size(); ++j)
			{
				int t=edge[newp][j].next;
				int c=edge[newp][j].c;
				int co=edge[newp][j].cost;
				if (mark[t]==true) continue;
				if (Dis[t]==-1||Dis[newp]+c<Dis[t]||
					(Dis[newp]+c==Dis[t]&&cost[t]>cost[newp]+co))
				{
					Dis[t]=Dis[newp]+c;
					cost[t]=cost[newp]+co;
				}
			}
			int min=2131231231;
			for (int j = 1; j <= n; ++j)
			{
				if (mark[j]==true) continue;
				if (Dis[j]==-1) continue;
				if (Dis[j]<min)
				{
					min=Dis[j];
					newp=j;
				}
			}
			mark[newp]=true;
		}
		printf("%d %d\n",Dis[T],cost[T]);
	}
	return 0;
}