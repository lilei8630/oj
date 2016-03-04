#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int seq[305];
int arr[305][305];
int pre[305];
int flag[305];
int ver_child[305][305];
int sort[305];
int compare(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

void init(int n){
	for (int i = 1; i <= n; ++i)
		pre[i] = i;
}
int find(int x){
	int r = x;
	while(pre[r]!=r)
		r = pre[r];
	//路径压缩
	int i = x,y;
	while(i!=r){
		y = pre[i];
		pre[i] = r;
		i = y;
	}
	return r;
}

void join(int x,int y){

	int fx = find(x);
	int fy = find(y);
	if (fx!=fy)
		pre[fx] = fy;
}

int main(){
	int n,len,cnt;
	char tmp[305];
	freopen("0input.txt","r",stdin);
	while(scanf("%d",&n)!=EOF){
		
		init(n);
		for (int i = 1; i <=n ; ++i)
			scanf("%d",seq+i);
		
		for (int i = 1; i <= n; ++i)
		{
		
			scanf("%s",tmp);
			len = strlen(tmp);
			for (int j = 0; j < len; ++j)
			{
				if (tmp[j]=='1')
					arr[i][j+1] = 1;

			}
		
			
		}
		
		for (int i = 1; i <=n; ++i)
		{
			for (int j = i; j <= n; ++j)
			{
				if (arr[i][j])
					join(i,j);
			}
		}
		//将并查集化成两层结构
		for (int i = 1; i <=n; ++i)
		{
			find(i);
		}

		for (int i = 1; i <= n; ++i)
		{
			if (pre[i]==i)
			{
				cnt = 0;
				for (int j = 1; j <=n; ++j)
				{
					if (pre[j]==i)
					{
						cnt++;
					}
				}
				if (cnt>1)
				{
					flag[i]=1;
					for (int j = 0; j <= n; ++j)
					{
						if (pre[j] ==i )
						{
							ver_child[i][j] = 1;
						}
						
					}
				}
			}
		}

		for (int i = 1; i <= n; ++i)
		{
			if (flag[i])
			{
				cnt =0;
				for (int j = 1; j <= n; ++j)
				{
					if (ver_child[i][j])
					{
						sort[cnt++] = seq[j];
					}
				}
				qsort(&sort[0], cnt, sizeof(int), compare);
				cnt = 0;
				for (int j = 1; j <= n; ++j)
				{
					if (ver_child[i][j])
					{
						seq[j]=sort[cnt++];
					}
				}
			}
		}

		for (int i = 1; i <= n; ++i)
		{
			printf("%d ",seq[i]);
		}
		printf("\n");

	}
	return 0;
}