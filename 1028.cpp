#include <stdio.h>
#include <algorithm>
#define N 100
using namespace std;

int Tree[N];

struct Road{
	int start;
	int end;
	int cost;
	int flag; // 标记是否已建
	bool operator <(const Road &A) const{
		return cost<A.cost;
	}
}roads[6000];

int findRoot(int x){
	if (Tree[x]==-1) return x;
	else{
		int tmp = findRoot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}

int main(){
	freopen("input.txt","r",stdin);
	int n,m;
	while(scanf("%d",&n)&&n){
		int sum=0;
		m=n*(n-1)/2;
		int i,a,b;
		for(int i=1;i<=n;i++)
			Tree[i]=-1;
		for (int i = 0; i < m; ++i)
		{
			scanf("%d%d%d%d",&roads[i].start,&roads[i].end,
				&roads[i].cost,&roads[i].flag);
			if (roads[i].flag==1)
			{
				a=findRoot(roads[i].start);
				b=findRoot(roads[i].end);
				if(a!=b)
					Tree[a]=b;
			}
		}
		sort(roads,roads+m);
		for (int i = 0; i < m; ++i)
		{
			a=findRoot(roads[i].start);
			b=findRoot(roads[i].end);
			if (a!=b)
			{
				Tree[a]=b;
				sum+=roads[i].cost;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}