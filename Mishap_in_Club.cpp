#include <stdio.h>
char arr[400];
int in;
int out;
int sum;
/*此题要求看过的最少人数。如果看到之前看到人进去，现在看到人出去。那么就把他当做之前看过进去的人 
如果之前看到人出去，现在又看到人进去，也把他们当做同一个人。此题转换为根据我做的进出记录，同时在商店 
中的最大人数*/ 
int main(){
	freopen("input.txt","r",stdin);
	while(scanf("%s",arr)!=EOF){
		in=out=sum=0;
		for (int i = 0; arr[i]!=0; ++i)
		{
			if(arr[i]=='+')  
            {  
                in++;  
                if(out) out--;  
                else sum++;  
            }  
            else   
            {  
                out++;  
                if(in) in--;  
                else sum++;  
            }  
		}
		printf("%d\n",sum);		
	}
	return 0;		
}