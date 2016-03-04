#include <stdio.h>
int main(){
	freopen("input.txt","r",stdin);
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		if (a==0&&b==0)
		{
			break;
		}
		int ans=1;//保存最终结果变量，初始值为1
		while(b!=0){
			if (b%2==1)
			{
				ans*=a;
				ans%=1000;
			}
			b/=2;
			a*=a;
			a%=1000;
		}
		printf("%d\n",ans);
	}
	return 0;
}