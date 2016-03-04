#include <stdio.h>
/*
这种思路是从左至右扫描表达式：将加数 减数 乘式的结果 除式的结果一次保存在
数组中，最后将数组求和。 
*/
int a[100];
int k;
char op;
int i;
int main(){
	freopen("input.txt","r",stdin);
	while(scanf("%d",&k)!=EOF){
		a[0]=0;
		i=0;
		a[++i]=k;
		while(scanf("%c",&op)!=EOF&&(op=='+'||op=='-'||op=='*'||op=='/')){
			scanf("%d",&k);
			if (op=='+')
			{
				a[++i]=k;
			}else if(op=='-'){
				a[++i]=0-k;
			}else if(op=='*'){
				a[i]*=k;
			}else
				a[i]/=k;
		}
		for (int k = 1; k <=i ; ++k)
			a[0]+=a[k];
		printf("%d\n",a[0]);
		




	}


}