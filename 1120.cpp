#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
char a[7];
int visited[7];
int l,top;
char s[7];//存储栈
void nn(){
	if (top==l)
	{
		s[top]='\0';
		printf("%s\n",s);
	}else
	{
		for (int i = 0; i < l; ++i)
		{
			if (visited[i]==0)
			{
				//进栈
				s[top++]=a[i];
				//标记为已访问
				visited[i]=1;
				//递归
				nn();
				//出栈
				top--;
				visited[i]=0;
			}
		}
	}
}

int main(){
	while(scanf("%s",a)!=EOF){
		l=strlen(a);
		top=0;
		for (int i = 0; i < l; ++i) visited[i]=0;
		nn();
	 	printf("\n");
	}
	return 0;
}