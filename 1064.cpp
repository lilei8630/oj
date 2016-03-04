#include <stdio.h>
int reverse(int a){
	int tmp[20];
	int reverse=0;
	int cnt=0;
	int factor=1;
	while(a>0){
		tmp[cnt++]=a%10;
		a/=10;
	}
	for (int i = cnt-1; i>=0; i--)
	{
		reverse+=(tmp[i]*factor);
		factor*=10;
	}
	//printf("%d\n",reverse );
	return reverse;
}
int main(){
	
	for(int i=1000;i<=1111;i++){
		if (i*9==reverse(i))
		{
			printf("%d\n",i);
		}
	}
}
