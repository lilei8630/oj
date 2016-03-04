#include <stdio.h>
#include <stdlib.h>
int main(){
	freopen("input.txt","r",stdin);
	int n,m,mul;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0&&m==0) break;
		mul=1;
		while(m--)
			mul=(mul*n)%1000;
		printf("%d\n",mul);
	}
	return 0;
}