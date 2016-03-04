#include <stdio.h>
int main(){
	freopen("input.txt","r",stdin);
	int aa,bb;
	int a[20],b[20];
	while(scanf("%d%d",&aa,&bb)!=EOF){
		int cnt_a=0,cnt_b=0;
	    int sum=0;
		while(aa>0){
			a[cnt_a++]=aa%10;
			aa/=10;
		}
		while(bb>0){
			b[cnt_b++]=bb%10;
			bb/=10;
		}
		for (int i = 0; i < cnt_a; ++i)
			for (int j = 0; j < cnt_b; ++j){

				sum+=a[i]*b[j];
			}
		printf("%d\n",sum);

	}
	return 0;
}