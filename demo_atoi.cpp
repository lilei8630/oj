#include <stdio.h>
#include <stdlib.h>

int main(){
	char * str="12312.12";
	int num = 123;
	char arr[20];

	int n=atoi(str);//把字符串转换成长整形数
	//arr=itoa(num,arr,2);
	printf("str:%s integer:%d\n",str,n);
	//printf("num:%d str:%s\n",num,arr);

	return 0;
}