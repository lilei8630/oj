#include <stdio.h>
#include <string.h>
int main(){
	freopen("input.txt","r",stdin);
	int a,b;
	char str[40];
	while(scanf("%d%s%d",&a,str,&b)!=EOF){
		int tmp=0,length=strlen(str),c=1;
		for (int i = length-1; i >=0 ; i--)
		{
			int x;
			if(str[i]>='0'&&str[i]<'9')
				x=str[i]-'0';
			else if(str[i]>='a'&&str[i]<='f')
				x=str[i]-'a'+10;
			else
				x=str[i]-'A'+10;
			tmp+=x*c;
			c*=a;
		}
		printf("tmp :%d\n",tmp);
		char ans[40],size=0;
		do{
			int x=tmp%b;
			ans[size++]=(x<10)?x+'0':x-10+'A';
			tmp/=b;
		}while(tmp>0);
		for (int i = size-1; i >=0; i--)
		{
			printf("%c",ans[i]);
		}
		printf("\n");
	}
	return 0;
}