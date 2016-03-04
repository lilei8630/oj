#include <stdio.h>
int main(){
	freopen("0input.txt","r",stdin);
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF){
		if (n<k)
		{
			printf("-1\n");
		}else{
			if(k==1){
				if (n==1)
				{
					printf("a\n");
				}else{
					printf("-1\n");
				}

			}else{
				//填充ababa...的
				int cnt_ab = n-(k-2);
				for (int i = 0; i < cnt_ab; ++i)
				{
					if (i%2==0)
						printf("a");
					else
						printf("b");
				}
				for (int i = 99; i < 99+k-2; ++i)
				{
					printf("%c",i);
				}
				printf("\n");
			}
			
		}

	}

}