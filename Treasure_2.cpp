#include <stdio.h>
#include <string.h>
char s[100005];
int res[100005];
int len;
void check(){
	int now=0,j=0;
	for (int i = 0; i < len; ++i)
	{
		if(s[i]=='(')
			now ++;
		else if(s[i]==')')
			now --;
		else
			now-=res[++j];
		if (now < 0)
		{
			printf("-1\n");
			return ;
		}
	}
	for (int i = 1; i <=j; ++i)
	
		printf("%d\n",res[i]);
		
			
		
}
int main(){
	freopen("0input.txt","r",stdin);
	int now,j;
	while(scanf("%s",s)!=EOF){
		len = strlen(s);
		now = j= 0;
		for (int i = 0; i < len; ++i)
		{
			if(s[i]=='(')
				now ++;
			else if(s[i]==')')
				now --;
			else{
				res[++j]=1;
				now--;
			}
			
		}
		if (now >0)
			res[j]+=now;
		check();

			
	}

}