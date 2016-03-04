#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
char str[10];
int top;
int stack[10010];

int main(){
	freopen("input.txt","r",stdin);

	while(scanf("%d",&n)!=EOF&&n){
		top=-1;
		memset(stack,0,sizeof(stack));
		for (int i = 0; i < n; ++i)
		{
			scanf("%s",str);
			if (str[0]=='A')
			{
				if (top>=0)
					printf("%d\n",stack[top]);
				else
					printf("E\n");
			}else if(str[0]=='P'){
				int tmp;
				scanf("%d",&tmp);
				stack[++top]=tmp;
			}else
				if (top>=0)
					top--;			
		}
		printf("\n");
	}
	return 0;
}