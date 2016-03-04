#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int num[1001];
int main()
{
	freopen("input.txt","r",stdin);
	int n,d;
	while(scanf("%d",&n)!=EOF)
	{
		for (int i = 1; i <= n; ++i)
			scanf("%d",&num[i]);
		scanf("%d",&d);
		if(pow(2,d)>n)
		{
			for (int j = (int)pow(2,d-1); j <= n; ++j)
			{
				if(j==n) printf("%d\n",num[j]);
				else printf("%d ",num[j]);
			}
		}
		else{
			if (d==1)
				printf("%d\n",num[1]);
			else{
				for (int j = (int)pow(2,d-1); j <= pow(2,d)-1; ++j)
				{
					if (j==pow(2,d)-1)
						printf("%d\n",num[j]);
					else
						printf("%d ",num[j]);
				}
			}

		}

	}
	return 0;
}