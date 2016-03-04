#include <stdio.h>
#include <string.h>
#define  N 1010
int matrix[N][N] ={0};
bool check(int x,int y){
	//当(x,y)位于九宫格中心时，判断是否为黑九宫格
	if (matrix[x-1][y-1]&&matrix[x-1][y]&&matrix[x-1][y+1]&&matrix[x][y-1]&&matrix[x][y]&&
		matrix[x][y+1]&&matrix[x+1][y-1]&&matrix[x+1][y]&&matrix[x+1][y+1])	
		return true;
	else
		return false;
}
int main(){
	freopen("input.txt","r",stdin);
	int n,m;
	int x,y,i;
	bool flag;
	while(scanf("%d%d",&n,&m)!=EOF){
		flag=false;
		memset(matrix,0,sizeof(matrix));
		for (i = 1; i <=m; ++i)
		{
			scanf("%d%d",&x,&y);
			matrix[x][y]=1;
			//(x,y)可能位于九宫格的左上、上、右上、左、中、右、左下、下、右下，分别判断这
			//九种情况对应的中心时候可以构成黑九宫格
			if (check(x,y)||check(x+1,y+1)||check(x+1,y)||check(x+1,y-1)||check(x,y+1)
				||check(x,y-1)||check(x-1,y+1)||check(x-1,y)||check(x-1,y-1))
			{
				if (!flag)
				{
					flag=true;
					printf("%d\n",i);
				}

			}
		}
		if (!flag)
		{
			printf("-1\n");
		}
		
	}
	return 0;
}