#include <stdio.h>
#include <string.h>
int main()
{
	freopen("input.txt","r",stdin);
	int x,t,a,b,da,db;
	int score_a[300];
	int score_b[300];
	bool flag;
	while(scanf("%d%d%d%d%d%d",&x,&t,&a,&b,&da,&db)!=EOF){
		memset(score_a,0,sizeof(score_a));
		memset(score_b,0,sizeof(score_b));
		flag = false;
		score_a[0]=0;
		score_b[0]=0;
		for (int i = 1; i <t+1; ++i)
		{
			score_a[i]=a-(i-1)*da;
			score_b[i]=b-(i-1)*db;	
		}
		/*
		for (int i = 0; i < t+1; ++i)
		{
			printf("score_a[%d]:%d\n",i,score_a[i]);
			
		}
		for (int i = 0; i < t+1; ++i)
		{
			
			printf("score_b[%d]:%d\n",i,score_b[i]);
		}*/
		for (int i = 0; i < t; ++i)
			for (int j = 0; j < t; ++j)
			{
				if (score_a[i]+score_b[j]==x)
				{
					flag=true;					
				}
			}
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}

}