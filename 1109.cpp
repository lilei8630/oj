#include <stdio.h>
#define N 1001
int Tree[N];
int findRoot(int x){
	if (Tree[x]==-1)
	{
		return x;
	}else{
		int tmp = findRoot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}

}
void init(){
	for (int i = 1; i <N; ++i)
	{
		Tree[i]=-1;
	}
}
int main()
{
	int m,n;
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		if (n==0)
		{
			break;
		}
		int a,b;
		while(m--){
			scanf("%d%d",&a,&b);
			a=findRoot(a);
			b=findRoot(b);
			if (a!=b)
			{
				Tree[a]=b;
			}
		}
	    int cnt=0;
	    for (int i = 1; i <=n; ++i)
		{
			if (Tree[i]==-1)
			{
				cnt++;
			}
		}
		puts(cnt==1?"YES":"NO");
		}
		return 0;

}