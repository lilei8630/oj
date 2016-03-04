#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 200

int Tree[N];

int findRoot(int x){
	if (Tree[x]==-1) return x;
	else{
		int tmp=findRoot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}
struct Edge
{
	int x;
	int y;
	int cost;	
	bool operator < (const Edge & A) const{
		return cost<A.cost;
	}
}edge[19900];

int main(){
	//freopen("input.txt","r",stdin);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0){
		//printf("n:%d m:%d ",n,m);
		int a,b,c;
		int cnt = 0;
		int cost = 0;
		int num=0;
		for (int i = 1; i <= N; ++i)
		{
			Tree[i]=-1;
		}
		
			while(n--){
				scanf("%d%d%d",&a,&b,&c);
				edge[cnt].x=a;
				edge[cnt].y=b;
				edge[cnt].cost=c;
				cnt++;
			}
			sort(edge,edge+cnt);
			for (int i = 0; i < cnt; ++i)
			{
				int fx=findRoot(edge[i].x);
				int fy=findRoot(edge[i].y);
				if (fx!=fy)
				{
					Tree[fx]=fy;
					cost+=edge[i].cost;
				}
			}
			for (int i = 1; i <= m; ++i)
			{
				if(Tree[i]==-1)
					num++;
			}
			if (num==1)
			{
				printf("%d\n",cost);
			}else{
				printf("?\n");
			}

		
		}
		return 0;
	}
		
	