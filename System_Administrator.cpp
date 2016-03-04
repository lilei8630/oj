#include <stdio.h>
int k;
int a_reach,a_lost;
int b_reach,b_lost;
int choice,m,n;

int main()
{
	freopen("input.txt","r",stdin);
	while(scanf("%d",&k)!=EOF)
	{
		a_reach=a_lost=b_lost=b_reach=0;
		for (int i = 0; i < k; ++i)
		{
			scanf("%d %d %d",&choice,&m,&n);
			if (choice==1)
			{
				a_reach+=m;
				a_lost+=n;
			}else{
				b_reach+=m;
				b_lost+=n;
			}

		}
		if (a_reach>=a_lost)
			printf("LIVE\n");
		else
			printf("DEAD\n");

		if (b_reach>=b_lost)
			printf("LIVE\n");
		else
			printf("DEAD\n");

	}
	return 0;
}