#include <stdio.h>
int n;
int arr[110];
int tmp;
int main(){

	while(scanf("%d",&n)!=EOF){
		for (int i = 1; i <=n; ++i)
			arr[i]=i;
		if (n%2==1)
			printf("-1\n");
		else{
			for (int i = 1; i <= n; ++i)
			{
				tmp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=tmp;
				i++;
			}
			for (int i = 1; i <= n; ++i)
			printf("%d ", arr[i]);
			printf("\n");
		}
	}
	return 0;
}