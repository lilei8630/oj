#include <stdio.h>
int arr[100010];
int main(){
	freopen("0input.txt","r",stdin);
	int n,t,len,sum,i,j;
	while(scanf("%d%d",&n,&t)!=EOF){
		//其中i,j是目前最长序列的上下界,len为目前的长度,max是已经花费的时间
		len=sum=0;
		for ( i = j=0; i < n; ++i)
		{
			scanf("%d",&arr[i]);
			sum+=arr[i];
			while(sum>t){
				sum-=arr[j++];

			}
			if (len<i-j+1)
			{
				len=i-j+1;
			}
		}
		printf("%d\n",len);

	}
}