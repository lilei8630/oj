#include <cstdio>
#include <cstring>
#include <cmath>
int main(){
	freopen("input.txt","r",stdin);
	int n;
	int T;
	while(scanf("%d",&T)!=EOF){
		if (T==0)
			break;
		while(T--){
			scanf("%d",&n);
			int r=(int)sqrt(n);
			int sum=0;
			if (r*r==n)
			{
				sum++;
				r-=1;
			}
			for (int i = 1; i <= r; ++i)
			{
				if (n%i==0)
				{
					sum+=2;
				}
			}
			printf("%d\n",sum);

		}
	}
	return 0;
}