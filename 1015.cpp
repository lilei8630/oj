#include <stdio.h>
int a,b,k;
int main(){
	freopen("input.txt","r",stdin);
	while(scanf("%d%d%d",&a,&b,&k)!=EOF){
		if (a==0&&b==0) break;
		if (a<<(32-k)==b<<(32-k))
			printf("-1\n");
		else
			printf("%d\n",a+b);

	}
}