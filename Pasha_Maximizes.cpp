#include <stdio.h>
#include <string.h>
/*
i=0:
9090000078001234 6
.     .
for循环完毕后，t=0，k=6
i=1:
9090000078001234 6
 .     .
for循环完毕后，t=2，k=6-(t-i)=5
i=2:
9900000078001234 5
  .    . 
i=3:
9900000078001234 5
   .    .
for循环完毕后,t=8, k=5-(8-3)=0
9900000078001234
9900000708001234
9900007008001234
9900070008001234
9900700008001234
9907000008001234
i=4:
9907000008001234 0
    .
    .
由于for循环不满足j-i<=k，所以终止。
*/
char s[20];
void swap(char *x,char *y)//使用指针传递地址
{
	char temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int main(){
	freopen("0input.txt","r",stdin);
	int k,len,t;
	while(scanf("%s%d",s,&k)!=EOF){
		//printf("%s %d\n",s,k);
		len = strlen(s);
		for (int i = 0; i < len; ++i)
		{
			t=i;  //t为在交换次数为k的条件下，比s[i]大的值中的最大值的索引
			for (int j = i+1; j < len&&j<=i+k; ++j)
			{
				if (s[j]>s[t])
					t=j;
			}
			k-=(t-i);
			//printf("i:%d t:%d",i,t);
			while(t!=i){
				swap(s+t,s+t-1);
				t--;
			}
			//printf(" %s\n",s);
		}
		printf("%s\n",s);
	}
	return 0;
	
}