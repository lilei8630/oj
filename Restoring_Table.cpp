#include <stdio.h>
#include <string.h>
int n;
int res[110];
int k;
int tmp;
int main(){
	freopen("input.txt","r",stdin);
	while(scanf("%d",&n)!=EOF){
		k=0;
		memset(res,0,sizeof(res));
		for (int i = 0; i < n; ++i)//读取n行，每行n个
		{
			for (int j = 0; j < n; ++j)
			{
				scanf("%d",&tmp);
				if (tmp!=-1)
				{
					res[k] = res[k]|tmp;
				}
				
			}
			k++;
			
		}
		for (int i = 0; i < n; ++i)
		
			printf("%d ",res[i]);
		
		printf("\n");

	}
	return 0;
}