#include <stdio.h>
#define N 200000
int main(){
	int i,j,m;
	int count;
	int a[N+1];
	for (int i = 0; i < N+1; ++i)
	{
		a[i]=1;
	}
	a[0]=0;
	a[1]=0;
	for (int i = 2; i < N+1; ++i)
	{
		for (int j = 2; j < N+1&&i*j<N+1; ++j)
		{
			a[i*j]=0;
		}
	}
	while(scanf("%d",&m)!=EOF){
		count = 0;
		for (int i = 0; i < N+1; ++i)
		{
			if (a[i])
			{
				count ++;
				if (count == m)
				printf("%d\n",i);
			}
		}
	}
	return 0;
}