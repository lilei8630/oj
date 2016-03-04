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
		flag=false;

		for (int i = 0; i <t; ++i)
		{
			score_a[i]=a-i*da;
			score_b[i]=b-i*db;	
		}
		if (x==0)//全错
		{
			flag=true;
		}
		for (int i = 0; i < t; ++i)//b错
		{
			if (x==score_a[i])
			{
				flag=true;
			}
		}
		for (int i = 0; i < t; ++i)//a错
		{
			if (x==score_b[i])
			{
				flag=true;
			}
		}
		for (int i = 0; i < t; ++i)//全对
			for (int j = 0; j < t; ++j)
			{
				if (score_a[i]+score_b[j]==x)
				{
					flag=true;
				}
			}
		if (flag)
		{
			printf("YES\n");
		}else
			printf("NO\n");


	}

}