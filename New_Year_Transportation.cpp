#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int arr[3*10010];

int main(){
	freopen("0input.txt","r",stdin);
	int n,t,pre;
	while(scanf("%d%d",&n,&t)!=EOF){
		for (int i = 1; i <= n-1; ++i)	
			scanf("%d",arr+i);
		pre = 1;
		while(pre+arr[pre]<=t){
			pre=pre+arr[pre];
			if (pre==t)
				break;
			
		}
		if (pre == t)
			printf("YES\n");
		else
			printf("NO\n");
 
	}
	return 0;

}