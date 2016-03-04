#include <stdio.h>
int main(){
	int n;
	int tmp;
	while(scanf("%d",&n)!=EOF){
		tmp=n*n;
		while(n>0){
			if (tmp%10!=n%10) break;
			tmp/=10;
			n/=10;
		}
		if (!n) puts("Yes!");
		else puts("No!");


	}
}