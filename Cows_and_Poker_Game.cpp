#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char arr[2*100010];
int main(){
	freopen("0input.txt","r",stdin);
	int n,cntA,cntI,cntF,res;
	while(scanf("%d",&n)!=EOF){
		cntA=cntF=cntI=res=0;
		memset(arr,0,sizeof(arr));

		for (int i = 0; i < n+1; ++i){
			scanf("%c",&arr[i]);
			if(i!=0){
				if (arr[i]=='A')
					cntA++;
				else if(arr[i]=='I')
					cntI++;
				else
					cntF++;
			}
		}
		//printf("A:%d F:%d I:%d \n",cntA,cntF,cntI );
		if (cntI==1)
		{
			printf("1\n");
		}else if (cntI==0)
		{
			printf("%d\n",cntA );
		}else
		{
			printf("0\n" );

		}
		    

		
		
			
	}
	return 0;
}