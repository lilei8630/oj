#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char arr[5][5];
char str[5];
int main(){
	
	freopen("0input.txt","r",stdin);
	int i=0;
	int cnt1,cnt2;
	int flag;
	while(scanf("%s",str)!=EOF){

		i++;
		int len = strlen(str);
		for (int j = 0; j < len; ++j)
			arr[i][j+1]=str[j];	

		if(i%4==0){
			flag = 0;
			for (int m = 1; m <= 3; ++m)
			{
				for (int n = 1; n <= 3; ++n)
				{
					cnt1 = cnt2 = 0;
					if (arr[m][n]=='#')	cnt1++;
					else cnt2++;

					if (arr[m+1][n]=='#')	cnt1++;
					else cnt2++;

					if (arr[m][n+1]=='#')	cnt1++;
					else cnt2++;

					if (arr[m+1][n+1]=='#')	cnt1++;
					else cnt2++;
					
					if (cnt1>=3||cnt2>=3){
						flag =1;
						break;
					}
					
					
					





				
				}
			}
			if (flag)
			{
				printf("YES\n");
			}else{
				printf("NO\n");
			}









			memset(arr,0,sizeof(arr));
			i=0;
		}
	}
	return 0;

}