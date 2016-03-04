#include <iostream>
using namespace std;

int prime(int n)
{
	int i;
	for (int i = 2; i*i <=n; ++i)
	{
		if (n%i==0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n,i,j;
	int count;
	while(cin>>n&&n)
	{
		count=0;
		for (int i = 3; i <= n/2; i+=2)
		{
			j=n-i;
			if (prime(j)&&prime(i))
			{
				count++;
			}

		}
		cout<<count<<endl;
	}
	return 0 ;
}