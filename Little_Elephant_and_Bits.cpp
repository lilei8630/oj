#include <stdio.h>
#include <string.h>
char arr[100010];
int len=0;
int find;
int main(){
	freopen("input.txt","r",stdin);
	while(scanf("%s",arr)!=EOF){
		len = strlen(arr);
		find = -1;
		for (int i = 0; i < len; ++i)
		{
			if (arr[i]=='0')
			{
				find = i;
				break;
			}
		}
		if (find==-1){
		
			for (int i = 0; i < len-1; ++i)
				printf("%c",arr[i]);
		}else{

			for (int i = 0; i < len; ++i)
			{
				if (i!=find)
				{
					printf("%c",arr[i]);
				}
			}
		}
		printf("\n");

	}
	return 0;
}