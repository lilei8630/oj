#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string.h>
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	char str1[50],str2[50];
	int n,c,i,j,k,cnt,flag;//flag - 标记是否为':',若是':'则标记为0 不是':' 标记为1
	                       // cnt - 小地址的个数 c - 判断小地址的字符数是否达到4
	cin >> n;
	while(n--){
		memset(str1,0,sizeof(str1));
		memset(str2,0,sizeof(str2));
		flag=cnt=0;
		scanf("%s",str1);
		k=strlen(str1);
		str1[k]=':';//保证最后一个小地址可以计入个数
		str1[k+1]='\0';
		for (int i = 0; i <= 38; ++i)//init
		{
			if(i==4||i==9||i==14||i==19||i==24||i==29||i==34)
				str2[i]=':';
			else 
				str2[i]='0';
		}
		for (int i = 0; i <=k; ++i)
		{
			if (str1[i]!=':')
				flag=1;
			else if(flag==1)
			{
				cnt++;
				flag=0;
			}
		}
		//printf("cnt:%d\n",cnt);
		c=0;
		j=38;
		for (int i = k-1; i >=0; i--)
		{
			if (str1[i]!=':')
			{
				c++;
				str2[j--]=str1[i];
			}
			if (str1[i]==':')
			{
				if (c==4)
					j--;
				else if (c==3)
					j=j-2;
				else if (c==2)
					j=j-3;
				else if (c==1)
					j=j-4;
				c=0;
			}
			if (str1[i]==':'&&str1[i-1]==':')
			{
				j=j-((8-cnt)*4+(8-cnt));
				i--;
			}
		}
		for (int i = 0; i <=37; ++i)
			cout<<str2[i];
		cout<<str2[38]<<endl;

	}
	return 0;

}