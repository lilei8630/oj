#include <cstdio>
#include <cstring>
#include <cstdlib>
int res[10010];//res[0]-阶乘结果的位数 res[1~res[0]]－结果的个十百千...
int main(){
	freopen("input.txt","r",stdin);
	int n;
	while(scanf("%d",&n)==1){
		int i,j;
		memset(res,0,sizeof(res));
		res[0]=1;
		res[1]=1;
		for (int i = 2; i <= n; ++i)//n-1次循环迭代
		{
			for (int j = 1; j <= res[0]; ++j)//模拟乘法运算，每位都乘以乘数，这样会导致res[i]不是一位数字
				res[j]=res[j]*i;
			for (int j = 1; j <= res[0]; ++j)//当res[i]不是一位时，需要处理进位
			{
				if (res[j]>=10)
				{
					res[j+1]+=res[j]/10;
					res[j]%=10;
					if (j==res[0])
						res[0]++;
				}
			}
		}
		for (int i = res[0]; i >= 1; i--)
			printf("%d",res[i]);
		printf("\n");

	}
}