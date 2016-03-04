#include <stdio.h>
int arr[105];

int main(){
	freopen("0input.txt","r",stdin);
	int m,n,res;
	while(scanf("%d%d",&m,&n)!=EOF){
		res=0;
		for (int i = 0; i < m; ++i)
			scanf("%d",&arr[i]);
		for (int i = 0; i < m-1; ++i)
		
			if (res<arr[i]-arr[i+1]-n)			
				res = arr[i]-arr[i+1]-n;
		printf("%d\n",res);
	}
	return 0;

}