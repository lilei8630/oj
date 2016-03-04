#include <stdio.h>
#include <string.h>
char s[5010];
int len;
int pos_e;
int hnum,tnum;
int ans;
int main(){
	freopen("0input.txt","r",stdin);

	while(scanf("%s",s)!=EOF){
		len = strlen(s);
		ans = pos_e=0;
		for (int i = 0; i < len-3; ++i)
		{
			if (s[i]=='b'&&s[i+1]=='e'&&s[i+2]=='a'&&s[i+3]=='r')
			{
				hnum = i-pos_e+1;
				tnum = len-(i+3);
				ans += hnum*tnum;
				pos_e=i+1;
			}
		}
		printf("%d\n",ans);

	}
	return 0;


}