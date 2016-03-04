#include <iostream>
using namespace std;
int gcd(int a,int b)
{
	return b!=0?gcd(b,a%b):a;
}

int main()
{
	freopen("input.txt","r",stdin);
	int t,n,m,i,a,b;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		a=m;
		for (i = 1; i < n; ++i)
		{
			cin>>m;
			if(a<m)
			{
				b=a;a=m;m=b;
			}
			a=a/gcd(a,m)*m;
		}
		cout<<a<<endl;
	}
	return 0;
}