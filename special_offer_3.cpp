#include <string.h>
#include <stdio.h>

typedef unsigned long long LL;

int fun(LL x){ //求x的位数
	int sum=0;
	while(x){
		sum++;
		x/=10;
	}
	return sum;
}

LL cal(int x){//求连续x个9的值
	LL sum=0;
	int i;
	for (i = 1; i<=x; ++i)
	{
		sum=sum*10+9;
	}
	return sum;
}

LL pow_10(int cnt){//求10的cnt次方
	LL s = 1;
	int i;
	for (i = 1; i <= cnt; ++i)
		s*=10;
	return s;
}

int main()
{
	freopen("input.txt","r",stdin);
	LL p,d;
	while(scanf("%llu%llu",&p,&d)!=EOF)
	{
		LL value = p-d;
		int cnt = fun(p);
		LL ans = cal(cnt);
		if (ans>=value && ans<=p)
		{
			printf("%llu\n",ans);
		}else{

			LL x=value%10;
			LL y=value/10;
			LL z=y*10+9;
			if (z>p)
			{
				z=z-9;
				printf("%llu\n",p);
				continue;
			}
			LL num=0,xx=0,yy=0;
			LL cnt=1;
			while(z<=p){
				cnt++;
				xx = z/pow_10(cnt);
				yy = z%pow_10(cnt);
				z=xx*pow_10(cnt)+cal(cnt);
				num=z;
			}
			num = xx* pow_10(cnt)+yy;
			cnt--;
			while(num<=p){
				num+=pow_10(cnt);
			}

			printf("%llu\n",num-pow_10(cnt));

		}
	}
	return 0;

}

























