#include <stdio.h>
#include <string.h>
#define N 1010
int matrix[N][N]={0};
//输入一个(x,y)，便将以(x,y)为中心的九宫格每个单元格＋1，
//当某个单元格达到9时，此时便形成黑九宫格。
int main()
{
	freopen("input.txt","r",stdin);
	int n,m;
	int x,y;
	bool flag;
	while(scanf("%d%d",&n,&m)!=EOF){
		flag = false;
		memset(matrix,0,sizeof(matrix));
		for (int i = 1; i <=m; ++i)
		{
			scanf("%d%d",&x,&y);
			for (int k = x-1; k <= x+1; ++k)
			{
				for (int j = y-1; j <= y+1; ++j)
				{
					matrix[k][j]++;
					//printf("i=%d,(%d,%d),matrix[%d][%d]=%d\n",i,x,y,k,j,matrix[k][j]);
					
					if (matrix[k][j]==9)
					{
						if (!flag)
						{
							flag=true;
							printf("%d\n",i);
						}
						
					}
					
				}
			}
		}
		if (!flag)
		{
			printf("-1\n");
		}

	}

}