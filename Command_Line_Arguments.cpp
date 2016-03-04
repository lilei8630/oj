#include <stdio.h>
#include <string.h>
char str[100010];
int main(){
	freopen("0input.txt","r",stdin);
	while(fgets(str,100010,stdin)){
		int len = strlen(str);
		//printf("len1:%d\n",len);
		if (str[len-1]=='\n')
			len--;
		//printf("len2:%d\n",len);
		for (int i = 0; i < len; ++i)
		{
			if (str[i]==' ')
				continue;
			printf("<");
			if (str[i]=='"')
			{
				for ( ++i; str[i]!='"'; ++i)
					printf("%c",str[i]);
				
			}else{
				for (; (i < len)&&str[i]!=' '; ++i)
				
					printf("%c", str[i]);
			}
			printf(">\n");
		}

	}
	return 0;

}