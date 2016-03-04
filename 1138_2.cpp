#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	int i,j,num[40],len,c,tmp,len_res;
	char s[40],res[200];
	while(scanf("%s",s)!=EOF){
		for (len = 0; s[len]; len++)
		{
			num[len]=s[len]-'0';
		}
		i=0;
		len_res=0;
		while(i<len){
			res[len_res++]=num[len-1]%2+'0';
			c=0;//借位
			for (j = i; j < len; ++j)
			{
			 	tmp=num[j];
			 	num[j]=(num[j]+c)/2;
			 	if (tmp&1)
			 	{
			 		c=10;
			 	}else{
			 		c=0;
			 	}
			}
			if(num[i]==0)
				i++;

		}
		for (i = len_res-1; i >= 0; i--)
		{
			cout<<res[i];
			//printf("%c",res[i]);
		}
			cout<<endl;
		//printf("\n");

	}
	return 0;

}