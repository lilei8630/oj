#include <stdio.h>
#include <string.h>
#include <math.h>
unsigned long long p,d,min;
int arr_min[40];
int tmp[40];
int len;
int changed;
long long result;
int num_9;
long long arr2long(int a[],int length){
	long long sum=0;
	for (int i = 0; i <length; i++)
	{
		sum=sum*10+a[i];
	}
	return sum;
}
int main(){
	freopen("input.txt","r",stdin);
	while(scanf("%llu%llu",&p,&d)!=EOF){
		len=0;
		min=p-d;
		//printf("min:%llu\n",min);
		while(min){
			tmp[len++]=min%10;
			min/=10;
		}
		for (int i = 0; i < len; ++i) arr_min[len-1-i]=tmp[i];
		changed = len-1;
		//continues = 0;
		
		while((arr2long(arr_min,len)<=p)&&changed>=0){
			arr_min[changed--]=9;
		}
		changed++;

		if (changed>0)
		{
			num_9=len-changed;
			while(1){
			arr_min[changed]--;
			if ((result=arr2long(arr_min,len))<=p)
				break;
			}
		}else{
			num_9=len;
			if(arr2long(arr_min,len)<=p)
				result=arr2long(arr_min,len);
			else{
				while(1){
				arr_min[changed]--;
				if ((result=arr2long(arr_min,len))<=p)
					break;
				}

			}
		}

		while(1){
			if ((result*10+9)<p)
			{
				num_9++;
			  	result=result*10+9;
			}else{
				break;
			}
		}

		int mm=p/result;
		printf("num_9:%d,mm:%d,%llu\n",num_9,mm,result);
		if(mm>2){
			if(mm==10){
				result =(mm-2)*pow(10,num_9)+result;
				printf("re:%llu,as:%f\n",result,pow(10,num_9));
			}
			
			else{

			    result =(mm-1)*pow(10,num_9)+result;
			 }
		}
		if (mm==2)
		{
			if (p%result!=0)
			{
				result =(mm-1)*pow(10,num_9)+result;
			}
		}
		printf("%llu\n",result);
	}
}