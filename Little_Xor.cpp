#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){

	freopen("input.txt","r",stdin);
	int n;
	int arr[110];
	int ans,tmp;
	while(scanf("%d",&n)!=EOF){
		ans =-1;
		for (int i = 0; i < n; ++i)
			scanf("%d",&arr[i]);
		for (int i = 0; i < n; ++i)
		{
			tmp=0;
			for (int j = i; j < n; ++j)
			{
				tmp^=arr[j];
				ans=max(ans,tmp);
			}

		}
		printf("%d\n",ans);
		

	}




}