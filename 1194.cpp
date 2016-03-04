#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	freopen("input.txt","r",stdin);
	int n;
	while(~scanf("%d",&n))
	{
		int num[10];
		memset(num,0,sizeof(num));
		int i=0;
		if(n==0)
			printf("0\n");
		else
		{
			while(n)
			{
				num[i++]=n%8;
				n/=8;
			}
			for (int j = i-1; j >=0; j--)
			{
				if (j==0)
				{
					printf("%d\n",num[j]);
				}else 
					printf("%d",num[j]);
			}
		}

	}
	return 0;

}