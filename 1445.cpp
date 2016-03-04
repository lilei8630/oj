#include <stdio.h>
#define N 1001
int Tree[N];

int findRoot(int x)
{
	if (Tree[x]==-1)
	{
		return x;
	}else{
		int tmp=findRoot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}

void init(){
	for (int i = 1; i < N; ++i)
	{
		Tree[i]=-1;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		int n,m;
		scanf("%d%d",&n,&m);
		int a,b;
		for (int i = 1; i <= m; ++i)
		{
			scanf("%d%d",&a,&b);
			a=findRoot(a);
			b=findRoot(b);
			if (a!=b)
			{
				Tree[a]=b;
			}
			
		}
		int cnt=1;
		for (int i = 1; i <= n; ++i)
		{
			if (Tree[i]==-1)
			{
				cnt++;
			}
		}
		printf("%d\n\n",cnt-1);
	}
}