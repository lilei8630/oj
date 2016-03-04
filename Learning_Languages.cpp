#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
这道题目考查并查集，特别注意每个人都不会语言的情况，此时结果为n。
*/
int father[105];
int lang[105][105];
int flag[105];
int set[105];


int find(int x){
	int r = x;
	while(father[r]!=r)
		r=father[r];
	//压缩
	int i = x,j;
	while(father[i]!=r){
		j=father[i];
		father[i]=r;
		i=j;
	}
	return r;
}

void merge(int x,int y){
	int fx = find(x);
	int fy = find(y);
	if (fx!=fy)
		father[fx]=fy;
}



int main(){
	freopen("0input.txt","r",stdin);
	int n,m,k,p,res,flag1=0;
	while(scanf("%d%d",&n,&m)!=EOF){
		//初始化
		flag1=0;
		memset(flag,0,sizeof(flag));
		memset(lang,0,sizeof(lang));
		memset(set,0,sizeof(set));
		for (int i = 1; i <= n; ++i)
			father[i]=i;
		//读入数据
		for (int i = 1; i <= n; ++i) 
		{
			scanf("%d",&k);
			if (k!=0)
			{
				flag[i]=1;
				for (int j = 1; j <= k; ++j)
				{
					scanf("%d",&p);
					lang[p][i]=1;
				}
			}
		}
		
		//构造并查集
		for (int i = 1; i <=m; ++i)
		{	
			int j,fa,fb;
			for (j = 1; j <= n; ++j)
			{
				if (lang[i][j]){
				
					fa = find(j);
					//printf("fa:%d\n",fa );
					break;
				}
			}
			for (j=j+1; j <= n; ++j)
			{
				if (lang[i][j])
				{
					fb=find(j);
					//printf("fa:%dfb:%d\n",fa,fb);
					merge(fa,fb);
				}
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			//printf("flag:%d ",flag[i]);
			if (flag[i]){
				flag1=1;
				break;
			}
		}

		if (!flag1)
		{
			printf("%d\n",n);
		}else{

			//统计将员工分成几类
			int fc;
			for (int i = 1; i <=n; ++i)
			{
				fc = find(i);
				set[fc]++;
			}
			res =0;
			for (int i = 1; i <= n; ++i)
			{
				if (set[i]>=1)		
					res++;
			}
			printf("%d\n",res-1);
		}
		

	}
	return 0;
}