#include <stdio.h>
#include <string.h>
struct bigInteger{
	int digit[10000];
	int size;
	void init(){
		for (int i = 0; i < 10000; ++i) {digit[i]=0; size=0;}
	}
	void set(int x){
			init();
			do{
				digit[size++]=x%10000;//对小整数4位为一个单位分解一次存入digit中
				x/=100000;
			}while(x!=0);//;别丢了
		}
		void output(){
			for (int i = size-1; i >=0 ; --i)
			{
				if (i!=size-1) printf("%4d",digit[i]);
				else printf("%d",digit[i]);
			}
			printf("\n");
		}
		bigInteger operator * (int x) const{
			bigInteger ret;
			ret.init();
			int carry=0;
			for (int i = 0; i < size; ++i)
			{
				int tmp = x*digit[i]+carry;
				carry = tmp/100000;
				tmp%=100000;
				ret.digit[ret.size++]=tmp;
			}
			if (carry!=0) ret.digit[ret.size++] = carry;
			return ret;
		}
}a;
int main(){
	freopen("input.txt","r",stdin);
	int n;
	while(scanf("%d",&n)!=EOF){
		a.init();
		a.set(1);
		for (int i = 2; i <=n; ++i)
			a=a*i;
		a.output();
	}
	return 0;
}














