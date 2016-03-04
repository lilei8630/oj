#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<int> edge[501];
queue <int> Q;

int main(){
	freopen("input.txt","r",stdin);
	int inDegree[501];
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for (int i = 1; i <= n; ++i)
		{
			inDegree[i]=0;
			edge[i].clear();
		}
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			inDegree[b]++;
			edge[a].push_back(b);
		}
		while(Q.empty()==false) Q.pop();
		for (int i = 1; i <= n; ++i)
		{
			if (inDegree[i]==0)	Q.push(i);
		}
		while(Q.empty()==false){
			int nowP=Q.front();
			Q.pop();
			printf("%d ",nowP);
			for (int i = 0; i < edge[nowP].size(); ++i)
			{
				inDegree[edge[nowP][i]]--;
				if (inDegree[edge[nowP][i]]==0)
				{
					Q.push(edge[nowP][i]);
				}	
			}
		}
	}

}
