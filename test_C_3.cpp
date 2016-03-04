#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	freopen("input.txt","r",stdin);
	double money[12];
	double average, sum;
	int i;
	while(scanf("%lf",&money[0]) != EOF)
	{
		sum = money[0];
		for(i = 1; i <12; i++)
		{
			scanf("%lf",&money[i]);
			sum += money[i];
		}
		average = sum / 12.0;
		printf("$%.2lf\n",average);
	}
	return 0;
}