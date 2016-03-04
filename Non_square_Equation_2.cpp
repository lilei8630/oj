#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


typedef long long LL;


LL digitSum(LL n)
{
	LL sum = 0;
	while(n)
	{
		sum+=n%10;
		n/=10;
	}
	return sum;
}


LL n;

int main()
{
	while(cin >> n)
	{
		
		LL ds,ans=-1,x,tmp;

		for ( int i = 1; i <= 100; ++i)
		{
			tmp = i*i/4+n;
			x= -i/2+sqrt(tmp);
			ds=digitSum(x);
			if (x*x+ds*x-n==0){
				ans=x;
				break;
			}
		}
		cout<<ans<<endl;

	}
	return 0;
}