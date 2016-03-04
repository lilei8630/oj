#include <stdio.h>
int arr[200010];
/*先将脸朝左的牛按顺序从右到左挤，再把脸朝右的牛按顺序从左向右挤，这样才能让损失量最少;
*/
int main(){
	freopen("0input.txt","r",stdin);
	int n;
	long long Have_Read0,Have_Read1;
	long long tatal0,total1,res;
	while(scanf("%d",&n)!=EOF){
		Have_Read0 = Have_Read1 = tatal0 = total1 = res = 0;
		for (int i = 0; i < n; ++i){
			scanf("%d",&arr[i]);
			if (arr[i]==0)
				tatal0 ++;
			else
				total1++;
		}

		for (int i = n-1; i >= 0; --i)
		{
			if (arr[i]==1)
				Have_Read1++;
			else{
				res+=(total1-Have_Read1);
			}

		}	

		printf("%lld\n", res);	



	}
	return 0;

}