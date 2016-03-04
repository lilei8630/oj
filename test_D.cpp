#include <stdio.h>
int main()
{
	int T;
	int n;
	int times;
	//int square[]=[1,4,9,16,25,36,49,64,81,100];
	while(scanf("%d",&T)!=EOF)
	{
		while(T--){
			scanf("%d",&n);
			times = 0;
			for (int i = 1; i*i<= n; ++i)
				times++;	
			printf("%d\n",times);
		}
		
	}
	return 0;
}
