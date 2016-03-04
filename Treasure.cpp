#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[100005];

int main(){
	freopen("0input.txt","r",stdin);
	int len,n1,n2,cnt,last,flag,last_num;
	while(scanf("%s",s)!=EOF){
		n1=n2=cnt=flag=0;
		len = strlen(s);
		//count # occur times and pos
		for (int i = 0; i < len; ++i)
		{
			if (s[i]=='#'){
				cnt++;
				last=i;
			}
		}
		//process the chars before pos
		for (int i = 0; i < last; ++i)
		{
			if (s[i]=='(')
				n1++;
			else if (s[i]==')'){
				n1--;
				if (n1<0)
				{
					printf("a\n");
					flag=1;
					break;
				}
			}else{
				n1--;
				if (n1<0)
				{
					printf("b\n");
					flag=1;
					break;
				}
			}

		}
		if (!flag) //chars before pos satisfy cons
		{	
			for (int i = last+1; i < len; ++i)
			{
				if (s[i]=='(')
				
					n1++;
				else{
					n1--;
					if (n1<1)
					{
						printf("c\n");
						flag=1;
					}
				}
			}	
		}
		n2=n1;
		//确定最后一个#替换的个数
		if (!flag){
			for (int i = last+1; i < len; ++i)
				if (s[i]=='(')		
					n1++;
				else
					n1--;
			if (n1>0)
				last_num =n1;
			else
				flag =1;
		}
		//验证在最后一个#填充last_num个）后续是否满足条件
		if (!flag)
		{

			
			
		}
		
		if (!flag)
		{
			for (int i = 0; i < cnt-1; ++i)
				printf("1\n");
			printf("%d\n",1+n1 );
		}else
			printf("-1\n");




	}
	return 0;

}