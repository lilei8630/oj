#include <iostream>
using namespace std;
int main()
{
	int a,b,c;
	for (int a = 0; a < 6; ++a)
	{
		for (int b = 0; b < 6; ++b)
		{
			for (int c = 0; c < 10; ++c)
			{
				if ((a*100+b*10+c)+(b*100+c*10+c)==532)
				{
					printf("%d %d %d\n",a,b,c);
				}
			}
		}
	}
}