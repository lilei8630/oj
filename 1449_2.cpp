#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <vector>
#define N 505
using namespace std;

int degree[N],res[N];

bool map[N][N];

vector<int> a[N];

int n,m;

void Topo(){
	int i,j,p;
	for (int i = 1; i <= n; ++i)
	{
		p = -1;
		for (int j = 1; j <= n; ++j)
		{
			if (degree[j] == 0)
			{
				degree[j]--;
				res[i] = p = j;
				break;
			}
		}
		for (int j = 1;j <= n; ++j)
		{
			if (map[p][j]==true)
			{
				map[p][j] = false;
				degree[j]--;
			}
		}
	}
}

void output(){
	
	printf("%d",res[1]);
	for (int i = 2; i <= n; ++i)
	{
		printf(" %d",res[i]);
	}
	printf("\n");
}

int main(){
	freopen("input.txt","r",stdin);
	int i,x,y;
	while(scanf("%d %d",&n,&m)!=EOF){
		memset(map,false,sizeof(map));
		memset(degree,0,sizeof(degree));
		memset(res,0,sizeof(res));
		for (int i = 1; i <= n; ++i)
			a[i].clear();
		
		for (int i = 1; i <= m; ++i)
		{
			scanf("%d %d",&x,&y);
			if (map[x][y] == false)
			{
				map[x][y] = true;
				degree[y]++;
			}
		}
		Topo();
		output();
	}
}