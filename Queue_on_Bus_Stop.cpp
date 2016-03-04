#include <stdio.h>
int arr[100];

int main(){
	freopen("0input.txt","r",stdin);
	int n,m,t,left,res;
	while(scanf("%d%d",&n,&m)!=EOF){
		left = m;
		res = 1;
		for (int i = 0; i < n; ++i)
			scanf("%d",arr+i);

		for (int i = 0; i < n; ++i)
		{

			if (left>=arr[i]){
				left -= arr[i];
				arr[i]=0;
			}else{
				res++;
				left = m;
				i--;
			}
			
		}
		printf("%d\n",res);
		
	}
	return 0;
}