#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	long long p,d,ans;
	scanf("%lld%lld",&p,&d);
	ans=p+1;
	p++;
	for (long long t = 10;;t*=10)
	{
		if(p%t>d) break;
		ans=p-p%t;
	}
	printf("%lld\n",ans-1);
	return 0;
}
