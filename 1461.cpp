#include <stdio.h>
char maze[8][8]; //保存地图信息
int n,m,t;
bool succeed;
int go[][2]={1,0,-1,0,0,1,0,-1};
void DFS(int x,int y,int time){
	for (int i = 0; i < 4; ++i)
	{
		int nx=x+go[i][0];
		int ny=y+go[i][1];
		if (nx<1||nx>n||ny<1||ny>m)
		{
			continue;
		}
		if (maze[nx][ny]=='X')
		{
			continue;
		}
		if (maze[nx][ny]=='D')
		{
			if (time+1==t)
			{
				succeed=true;
				return;
			}else{
				continue;//经过的点不能再经过
			}
		}//该位置为大门
		maze[nx][ny]='X';
		DFS(nx,ny,time+1);
		maze[nx][ny]='.';
		if (succeed)
		{
			return;
		}

	}

}
int main()
{
	while(scanf("%d%d%d",&n,&m,&t)){
		if (n==0&&m==0&&t==0) break;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%s",maze[i]+1);
		}//输入
		succeed=false;
		int sx,sy;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (maze[i][j]=='D')
				{
					sx=i;
					sy=j;
				}
			}
		}//寻找D
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				//找到S点后，直接判断S和D的奇偶关系是否和T相符，若不符合直接跳出循环
				if (maze[i][j]=='S'&&(i+j)%2==((sx+sy)%2+t%2)%2)
				{
					maze[i][j]='X';//将起点标记为墙
					DFS(i,j,0);

				}
			}
		}//寻找S
		puts(succeed==true?"YES":"NO");

	}
}