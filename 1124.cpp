#include <stdio.h>
int dr(int num){
	int dr = 0;
	while(num>0){
		dr+=num%10;
		num/=10;
	}
	//printf("dr method:%d\n", dr);
	return dr;
}
int main(){
	freopen("input.txt","r",stdin);
	int a;
	int result=0;

	while(scanf("%d",&a)!=EOF){
		if (a==0) break;
		result=dr(a);
		while(result>=10){
			result=dr(result);
		}

		printf("%d\n\n",result);

	}
}