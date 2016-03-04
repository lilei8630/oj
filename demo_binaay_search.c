#include <stdio.h>
#include <stdlib.h>
int  binary_search(unsigned long long a[],int n,unsigned long long key);
int main(){
	int n = 0;
	unsigned long long * arr;
	unsigned long long tmp;
	int num=0;
	FILE * fin = fopen("input.txt","r");
	if (fin==NULL)
	{
		printf("The input file doesn't exit.\n");
		exit(1);
	}
	
	while(fscanf(fin,"%llu",&tmp)!=EOF)
	 
		n++;
		
    printf("n:%d\n",n);
	arr =(unsigned long long * )malloc(n*sizeof(unsigned long long));
	if (arr == NULL)
	{
		printf("Memory allocate error\n");
		exit(1);
	}

	fseek(fin,0,SEEK_SET);

	while(fscanf(fin,"%llu",&tmp)!=EOF)
	{
		arr[num++]=tmp;
	}
	printf("index:%d\n",binary_search(arr,n,453089));

	fclose(fin);

	return 0;
}

int binary_search(unsigned long long array[],int n,unsigned long long value)  
{  
    int left=0;  
    int right=n-1;  
    //如果这里是int right = n 的话，那么下面有两处地方需要修改，以保证一一对应：  
    //1、下面循环的条件则是while(left < right)  
    //2、循环内当array[middle]>value 的时候，right = mid  
  
    while (left<=right)          //循环条件，适时而变  
    {  
        int middle=left + ((right-left)>>1);  //防止溢出，移位也更高效。同时，每次循环都需要更新。  
  
        if (array[middle]>value)  
        {  
            right =middle-1;   //right赋值，适时而变  
        }   
        else if(array[middle]<value)  
        {  
            left=middle+1;  
        }  
        else  
            return middle;    
        //可能会有读者认为刚开始时就要判断相等，但毕竟数组中不相等的情况更多  
        //如果每次循环都判断一下是否相等，将耗费时间  
    }  
    return -1;  
}  