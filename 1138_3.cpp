#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>

using namespace std;
int main()
{
	char s[40];//待处理的10进制字符串
	int num[40];//与s对应的int串
	char result[200];
	int index;
	int size;//s和num的长度
	while(scanf("%s",s)!=EOF)
	{
		for (int i = 0; s[i]; ++i){
			num[i]=s[i]-'0';
			size = i;
		}
		index=0;
		while(index<size)
		{
			result[index++]=num[len-1]%2+'0';
			c=0; //借位
			for (int j = i; j < len; ++j)
			{
				tmp=num[j];
				
			}



		}






	}

}