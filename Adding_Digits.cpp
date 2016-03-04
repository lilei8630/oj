#include <stdio.h>
#include <string.h>
int arr[100010];
int  Int2Arr(int x){
	int num = 0,i=0,len=-1,right;
	while(x){
		arr[num++]=x%10;
		x/=10;
	}	
	len = num;
	right=num-1;
	
	while(i<right)
	{
		int tmp=arr[i];
		arr[i]=arr[right];
		arr[right]=tmp;
		i++;
		right--;
	}
	
	return len;
}


int main(){
	freopen("input.txt","r",stdin);
	int a,b,n,tmp,find,len;
	
	while(scanf("%d %d %d",&a,&b,&n)!=EOF){
		find=-1;
		tmp = 0;
		len = 0;
		memset(arr,0,sizeof(arr));
		for (int i = 0; i <=9; ++i)
		{
			tmp = a*10+i;
			if (tmp%b==0)
			{
				find=i;
				break;
			}
		}
		if (find==-1)	
			printf("-1\n");
		else
		{
			//printf("tmp:%d\n",tmp);
			len = Int2Arr(tmp);
			
			len +=(n-1);

			for (int i = 0; i < len; ++i)
			{
				printf("%d",arr[i]);
			}
			printf("\n");
			

		}

		

	}
}