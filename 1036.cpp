#include <iostream>
using namespace std;
int main()
{
	int N;
	while(cin>>N&&N>=1&&N<=99)
	{
		int x,y,z;
		int i,j;
		int count;
		int flag=0;
		cin>>x>>y>>z;
		for (int i = 9; i >= 1; i--)
		{
			for (int j = 9; j >= 0; j--)
			{
				if ((i*10000+x*1000+y*100+z*10+j)%N==0)
				{
					flag++;
					count=(i*10000+x*1000+y*100+z*10+j)/N;
					cout<<i<<" "<<j<<" "<<count<<endl;
					break;
				}
				
			}
			if (flag==1)
				{
				break;
				}
			
			
		}
		if (flag==0)
			{
				cout<<"0"<<endl;
			}

	}
}