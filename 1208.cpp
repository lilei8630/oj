#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TEN 2000
#define TWO 4000

char A[TEN],B[TWO];
int C[TEN];

int divideToBinary();
void multiplyToDecimal(int k);

int main()
{
	int k;

	while(scanf("%s",A)!=EOF)
	{
		k=divideToBinary();
		multiplyToDecimal(k);
	}

	return 0;
}

int divideToBinary()
{
	int i,k,sum,len,d;
	memset(B,0,sizeof(B));
	sum=1;
	len =strlen(A);
	k=0;
	//转换为2进制
	while(sum){
		sum=0;
		for (int i = 0; i < len; ++i)
		{
			d=(A[i]-'0')/2;
			sum+=d;
			if (i==len-1)
			{
				B[k++]=(A[i]-'0')%2+'0';
			}else{
				A[i+1]+=(A[i]-'0')%2*10;
			}
			A[i]=d+'0';
		}
	}
	B[k]='\0';
	//printf("%s\n",B);
	return k;
}
/*
这个算法可以避免2^n超过int的表示范围
比如计算1011 0101的十进制数
0*2+1 ＝ 1
1*2+0 ＝ 2
2*2+1 ＝ 5
5*2+1 ＝ 11
11*2+0 ＝ 22
22*2+1 ＝ 45
45*2＋0 ＝ 90
90*2＋1 ＝ 181
*/
void multiplyToDecimal(int k)
{
	int i,j,c,len;//10进制字符串的长度
	memset(C,0,sizeof(C));//C[0]－最低位 C[len-1]-最高位
	len =1;
	for (i = 0; i < k; ++i)
	{
		for (j = 0; j < len; ++j)
		{
			C[j]*=2;
		}
		C[0]+=B[i]-'0';
		for (j= c = 0; j < len; ++j)
		{
			C[j]+=c;
			if (C[j]>=10)
			{
				c=C[j]/10;
				C[j]%=10;
			}else{
				c=0;
			}
		}
		while(c>0){
			C[j++] = c%10;
			c/=10;
		}
		len=j;
		//printf("i:%d,len:%d,C[0]:%d,C[1]:%d,C[2]:%d\n\n",i,len,C[0],C[1],C[2]);
	}
	for (i = len-1; i >= 0; i--)
	{
		printf("%d",C[i]);
	}
	printf("\n");		
}

































