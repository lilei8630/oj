#include <stdio.h>
bool sym(int n){
	bool flag=true;
	int buf[10];
	int cnt=0;
	while(n){
		buf[cnt++]=n%10;
		n/=10;
	}
	int start=0,end=cnt-1;
	while(start<=end){
		//printf("%d %d\n",buf[start],buf[end]);
		if (buf[start]!=buf[end])
		{
			flag=false;
			break;
		}
		start++;
		end--;

	}
	return flag;

}
int main(){
	for (int i = 1; i < 256; ++i)
	{
		if (sym(i*i))
		{
			printf("%d\n",i);
		}
	}
	
}