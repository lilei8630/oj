#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char str[1010];
int cnt[30];
char tmp[30];
int k;
int len;
bool flag;
int p;
int cmp(const void * a,const void * b){
	return *(char *)b -*(char *)a;
}


int main(){
	freopen("input.txt","r",stdin);

	while(scanf("%d",&k)!=EOF){
		p=0;
		flag=true;
		memset(cnt,0,sizeof(cnt));
		memset(str,0,sizeof(str));
		memset(tmp,0,sizeof(tmp));
		scanf("%s",str);
		len=strlen(str);
		//printf("len:%d\n",len);
		qsort(str,len,sizeof(char),cmp);
		//printf("sort_str:%s\n",str);
		for (int i = 0; i < len; ++i)
		{
			int num=1;
			while(str[i]==str[i+num]){
				num++;
				
			}
			i=i+num-1;
			//printf("num:%d\n",num);
			if (num%k!=0)
			{
				flag=false;	
			}
			
		}
		if (flag)
		{
			for (int i = 0; i < len; i+=k)
			{
				tmp[p++]=str[i];
			}
			tmp[p]=0;
			for (int i = 0; i < k; ++i)
			{
				printf("%s",tmp);
			}
			//for (int i = 0; i < p; ++i) printf("%c",tmp[i]);
			
			printf("\n");
				
		}else{
			printf("-1\n");

		}

	}
	return 0;

}