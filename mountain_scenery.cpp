#include <stdio.h>
#include <string.h>

int n,k;
int array[500];
bool flag[500];
int num;
int main(){
	freopen("input.txt","r",stdin);
	while(scanf("%d%d",&n,&k)!=EOF){
		num=0;
		memset(array,0,sizeof(array));
		memset(flag,0,sizeof(flag));
		for (int i = 0; i < 2*n+1; ++i)
			scanf("%d",&array[i]);
		for (int i = 1; i < 2*n+1; i+=2)
		{
			if (array[i]-1>array[i-1]&&array[i]-1>array[i+1])
			{
				flag[i]=true;		
			}
		}
	}
	for (int i = 0; i < 2*n+1; ++i)
	{
		if (num<k&&flag[i])
		{
			printf("%d ",array[i]-1);
			num++;
		}else{
			if (i==2*n)
			{
				printf("%d",array[i]);
			}else
				printf("%d ",array[i]);
		}
		
	}
	printf("\n");


	//for (int i = 0; i < 2*n+1; ++i) printf("%d ", array[i]);
	//for (int i = 0; i < 2*n+1; i++) printf("%d ", flag[i]);
	


	return 0;
}