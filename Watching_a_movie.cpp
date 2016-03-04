#include <stdio.h>

int main(){
	int n,x,res,l,r,cur;
	freopen("0input.txt","r",stdin);
	while(scanf("%d%d",&n,&x)!=EOF){
		res = 0;
		cur = 1;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d",&l,&r);
			//printf("cur:%d l:%d r:%d\n",cur,l,r);
			while(cur<=l){
				cur += x;
			}
			cur -= x;
			//printf("cur:%d\n",cur);
			res +=(r-cur+1);
			cur = r+1;
			//printf("res:%d\n",res);
		}
		printf("%d\n",res);
	}
	
	return 0;

}