#include <stdio.h>
#include <string.h>
char lec[3005][12];
char bes[3005][12];

int main(){
	freopen("0input.txt","r",stdin);
	int n,m,len1,len2;
	char lang1[12],lang2[12];
	while(scanf("%d %d",&n,&m)!=EOF){
	//	printf("n:%d m:%d\n",n,m );
		for (int i = 0; i < m; ++i)
		{
			scanf("%s %s",lang1,lang2);
	//		printf("%s %s\n",lang1,lang2);
			len1 = strlen(lang1);
			len2 = strlen(lang2);
			if (len1<=len2)
			{
				strcpy(lec[i],lang1);
				strcpy(bes[i],lang1);

			}else{
				strcpy(lec[i],lang1);
				strcpy(bes[i],lang2);
			}
		}
	//	for (int i = 0; i < m; ++i)
	//			printf("bes[%d]:%s\n",i,bes[i]);
		
		for (int i = 0; i < n; ++i)
		{
			scanf("%s",lang1);
			//printf("lang1:%s\n",lang1);
			
			for (int j = 0; j < m; ++j)
			{
				if (strcmp(lang1,lec[j])==0)
				{
					printf("%s ",bes[j]);
					break;
					//printf("lang:%s best:%s\n",lang1,bes[j]);
				}

			}
			
		}
		
		printf("\n");
		
		

	}
	return 0;
}