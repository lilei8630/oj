#include <stdio.h>
#include <string.h>
int arr[105];
int n;
int ans;
int x;
int num;
int max(int x,int y){
	return x > y ? x : y;
}
int main(){
	freopen("input.txt","r",stdin);
	while(scanf("%d",&n)!=EOF){
		ans=0;
		memset(arr,0,sizeof(arr));
		for (int i = 1; i <= n; ++i) scanf("%d",&arr[i]);
		if (n==1||n%2==0) {
			printf("-1\n");
		}else{
			for (int i = n; i >=3; i-=2)
			{
				
				x=(i-1)/2;
				num=max(arr[i],arr[i-1]);
				arr[x]-=num;
				arr[i]=arr[i-1]=0;
				if (arr[x]<0)
					arr[x]=0;
				ans+=num;
			}
			ans+=max(max(arr[1],arr[2]),arr[3]);
			printf("%d\n",ans);
		}
		
		
		

	}
	return 0;
}