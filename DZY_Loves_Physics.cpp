#include <stdio.h>
double arr[505];

int main(){
	freopen("0input.txt","r",stdin);
	int n,m,src,end,val;
	double res,density;
	while(scanf("%d%d",&n,&m)!=EOF){
		res = 0;
		for (int i = 1; i <= n; ++i)
			scanf("%lf",arr+i);
		for (int i = 0; i < m; ++i)
		{
			scanf("%d%d%d",&src,&end,&val);
			density = (arr[src]+arr[end])/val;
			//printf("i:%d src:%lf end:%lf val:%d den:%lf\n",i,arr[src],arr[end],val,density);

			if (density>res)
			{
				res = density;

			}
			
		}
		printf("%.16lf\n",res);
	}
	return 0;
}