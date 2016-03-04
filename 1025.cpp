#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>

using namespace std;

int list[35];
int dp[3000000];
int max(int a,int b)
{
	return a>b?a:b;
}
void init()
{
	memset(list,0,sizeof(list));
	memset(dp,0,sizeof(dp));
}
int main()
{
	double budgt,value,sum;
	int budgt_int,n,m,sum_int;
	char ch;
	int flag;
	
	int cnt=0;
	while(scanf("%lf%d",&budgt,&n)!=EOF)
	{
		init();
		if (n==0)
			break;
		budgt_int =(int)(budgt*100);
		for (int i = 1; i <=n; ++i)//每张发票
		{
			scanf("%d",&m);
			flag=1;
			sum=0;
			for (int j = 1; j <=m; ++j)//每项
			{ 
				scanf(" %c:%lf",&ch,&value);
				if (value>600.00||ch-'A'>=3)
					flag=0;
				sum=sum+value;
					
			}
			//printf("flag:%d  sum:%lf\n",flag,sum);
			if (flag==1&&sum<=1000.00)
				{
					sum_int=(int)(sum*100);
					list[++cnt]=sum_int;
					//printf("list[%d]=%d\n",cnt,list[cnt]);
				}

		}

		
		for (int i = 1; i <= cnt; ++i)
		{
			for (int j = budgt_int; j >=list[i]; j--)
			{
				dp[j]=max(dp[j],dp[j-list[i]]+list[i]);
			}
		}
		printf("%.2lf\n",dp[budgt_int]/100.0 );
		

	}
}