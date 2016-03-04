#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
unsigned long long arr1[100010];
unsigned long long arr2[100010];
unsigned long long ans;

int Compare(const void *a, const void *b) {
    return *(int *)a-*(int *)b;
}

int main(){
	freopen("0input.txt","r",stdin);
	int n,m,k,l,r,p;
	while(scanf("%d",&n)!=EOF){
		memset(arr1,0,sizeof(arr1));
		memset(arr2,0,sizeof(arr2));
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d",&m);
			arr1[i]=arr2[i]=m;
		}
		qsort(&arr2[1], n, sizeof(unsigned long long), Compare);
		
		ans =0;
		for (int i = 1; i <= n; ++i)
		{
			ans+=arr1[i];
			arr1[i]=ans;
			
		}
		ans =0;
		for (int i = 1; i <=n; ++i)
		{
			ans+=arr2[i];
			arr2[i]=ans;	
		}
		//for (int i = 0; i <= n; ++i) printf("%llu ",arr1[i]);
		//for (int i = 0; i <= n; ++i) printf("%llu ",arr2[i]);
		scanf("%d",&k);
		for (int i = 0; i < k; ++i)
		{
			ans=0;
			scanf("%d%d%d",&p,&l,&r);
			if (p==1)
			{
				ans=arr1[r]-arr1[l-1];
					
			}else{
				ans=arr2[r]-arr2[l-1];
			}
			printf("%llu\n",ans);
			
		}
	
	}
	return 0;

}