#include <stdio.h>
#include  <string.h>
int main()
{
	freopen("input.txt","r",stdin);
	double sum;
	double balance[12];
	while(scanf("%lf",&balance[0])!=EOF)
	{
		sum=0;
		
		for (int i =1; i <= 11; ++i)
		{
			scanf("%lf",&balance[i]);
		}
		for (int i = 0; i <12; ++i)
		{
			sum+=balance[i];
		}
		memset(balance,0,sizeof(balance));
		printf("$%.2lf\n",sum/12);

	}
	return  0;
	
}