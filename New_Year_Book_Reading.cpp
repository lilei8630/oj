#include <stdio.h>
#include <string.h>
int weight[505];
int order[505];
int flag[505];
int readOrder[1005];
int main(){
	freopen("0input.txt","r",stdin);
	int n,m,num,cur,res,now,tmp;
	while(scanf("%d%d",&n,&m)!=EOF){
		cur=1,res=0;
		memset(flag,0,sizeof(flag));
		for (int i = 1; i <= n; ++i)
			scanf("%d",weight+i);
		for (int i = 1; i <= m; ++i){
			scanf("%d",&num);
			readOrder[i]=num;
			if (!flag[num]){
				flag[num]=1;
				order[cur++]=num;
			}
		}
		//for (int i = 1; i <= n; ++i) printf("%d ",order[i]);
		//	printf("res:%d \n",res);

		for (int i = 1; i <=m; ++i) {
			now = readOrder[i];
			for (int j = 1; j <= n; ++j)
			{
			 	if (now!=order[j])
			 	{
			 		res += weight[order[j]];
			 	}else{
			 		tmp= j;
			 		break;
			 	}
			}
			
			for (int j = tmp; j >1 ; --j)
			{
				order[j]=order[j-1];
			}
			order[1] = now;
			//for (int i = 1; i <= n; ++i) printf("%d ",order[i]);
			//printf("res:%d \n",res);
		}
		printf("%d\n",res);

	}
	return 0;
}