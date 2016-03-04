#include <stdio.h>
int gcd(int a,int b)
{
	return b!=0?gcd(b,a%b):a;
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		printf("%d\n",a*b/gcd(a,b));
	}
}