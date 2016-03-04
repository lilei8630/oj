#include <iostream>
using namespace std;
int ex_pow(int a,int b)
{
	int  sum;
	a%=1000;
	sum=1;
	while(b!=0)
	{
		if (b%2==1)
		{
			sum*=a;
			sum%=1000;
		}
		b/=2;
		a*=a;
		a%=1000;
	}
	return sum;
}

int main()
{
	freopen("input.txt","r",stdin);
	long long a,b;
	while(cin>>a>>b)
	{
		if (a==0&&b==0)
			break;
		cout<<ex_pow(a,b)<<endl;
	}
	return 0;
}