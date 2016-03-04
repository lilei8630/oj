#include <stdio.h>
#include <string.h>
struct bigInteger{
	int digit_zhengshu[1000];
	int size_zhengshu;
	int digit_xiaoshu[1000];
	int size_xiaoshu;

	void init(){
		for (int i = 0; i < 1000; ++i)
		{
			digit_zhengshu[i]=0;
			digit_xiaoshu[i]=0;

		}
		size_xiaoshu=0;
		size_zhengshu=0;
	} 
	void set(char str[]){
		init();
		int len = strlen(str),t,sum,tmp,count,i;
		
		for (i = 0; i < len; ++i)//find '.'
			if (str[i]=='.')
					break;
		tmp = i;//'.'的位置
		i--;
		sum = 0;
		t=1;//权重
		count = 0;
		//处理整数
		for (int j = i; j >= 0; j--)
		{
			sum+=(str[j]-'0')*t;
			t*=10;
			count++;
			if (count==4||j==0)
			{
				digit_zhengshu[size_zhengshu++]=sum;
				sum=0;
				t=1;
				count=0;
			}
		}
		//处理小数
		i=tmp+1;
		for (int j = i; j < len; ++j)
			digit_xiaoshu[size_xiaoshu++]=str[j]-'0';
		
		
	}


	bigInteger operator +(const bigInteger &A) const{
		//先加小数，在加整数
		bigInteger ret;
		ret.init();
		int carry=0,max,sum;

		if (size_xiaoshu>=A.size_xiaoshu)
		{
			max = size_xiaoshu;
		}else 
		 	max = A.size_xiaoshu;


		for (int i = max -1; i >= 0; i--)
		{
			sum = digit_xiaoshu[i]+A.digit_xiaoshu[i]+carry;
			ret.digit_xiaoshu[i]=sum%10;
			carry=sum/10;
		}

		for (int i = max-1; i >= 0; i--)
		{
			if (ret.digit_xiaoshu[i]!=0)
			{
				
				ret.size_xiaoshu=i+1;
				break;
			}
		}
		
		for (int i = 0; i < size_zhengshu||i<A.size_zhengshu; ++i)
		{
			sum=digit_zhengshu[i]+A.digit_zhengshu[i]+carry;
			ret.digit_zhengshu[ret.size_zhengshu++]=sum%10000;
			carry=sum/10000;
		}
		if (carry)
			ret.digit_zhengshu[ret.size_zhengshu++]=carry;
		return ret;
	}
	
	void print(){
		//输出整数
		for (int i = size_zhengshu-1; i >= 0; --i)
		{
			if (i==size_zhengshu-1)
				printf("%d",digit_zhengshu[i]);
			else 
				printf("%04d",digit_zhengshu[i]);
		}
		printf(".");
		if (size_xiaoshu==0)
		
			printf("0");
		else
			for (int i = 0; i < size_xiaoshu; ++i)
				printf("%d", digit_xiaoshu[i]);
		printf("\n");
	}
};
int main(){
	freopen("input.txt","r",stdin);
	int n,i;
	bigInteger a,b,c;
	char str1[200],str2[200];
	while(scanf("%d",&n)!=EOF){
		for (int i = 0; i < n; ++i){
			scanf("%s%s",str1,str2);
			a.set(str1);
			b.set(str2);
			c=a+b;
			c.print();
			
		}
		
	}
	return 0;
}
































