#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_CODE_LENGTH 40//宏定义没有；
struct vocab_word
{
	long long cn;
	int * point;
	char *word,*code,codelen;	
};
long long vocab_size,a,b,k,min1,min2,i;//词汇表大小
struct vocab_word * vocab;


int VocabCompare(const void *a,const void *b)
{
	return *((long long *)b)-*((long long *)a);
}

int main()
{
	freopen("input.txt","r",stdin);
	scanf("%lld",&vocab_size);
	//printf("vocab_size:%lld\n",vocab_size);
	vocab = (struct vocab_word *)calloc(vocab_size,sizeof(struct vocab_word));
	for (i = 0; i < vocab_size; ++i)
	{
		vocab[i].code = (char *)calloc(MAX_CODE_LENGTH, sizeof(char));
    	vocab[i].point = (int *)calloc(MAX_CODE_LENGTH, sizeof(int)); 
    	//printf("allocate memory to vocab[%lld]\n",i);
	}
	
	long long *count = (long long *)calloc(vocab_size*2-1,sizeof(long long));
	long long *binary = (long long *)calloc(vocab_size*2-1,sizeof(long long));
	long long *parent_node = (long long *)calloc(vocab_size*2-1,sizeof(long long));
	long long point[MAX_CODE_LENGTH];
	char code[MAX_CODE_LENGTH];
	for (i = 0; i < vocab_size; ++i)
	{	scanf("%lld",&count[i]);
		//printf("%lld",count[i]);
	}
	
	//for (i = 0; i < vocab_size; ++i) printf("%lld ",count[i]);
	for (i = vocab_size; i < vocab_size*2-1; ++i) 
		count[i]=1e15;
	
	//sort
	qsort(count,vocab_size,sizeof(long long),VocabCompare);
	//for (i = 0; i < vocab_size; ++i) printf("%lld ",count[i]);
	
	for (i = 0; i < vocab_size; ++i)
		vocab[i].cn=count[i];

	//for (i = 0; i < vocab_size; ++i) printf("%lld ",vocab[i].cn);
	
	long long pos1 = vocab_size-1;
	long long pos2 = vocab_size;
	
	for (a = 0; a < vocab_size-1; ++a)//迭代vocab_size-1次构造huffman树
	{
		//每次寻找两个最小的点min1和min2(次小)，最小点为0，次小点为1
		if (pos1>=0)
		{
			if (count[pos1]<count[pos2])
			{
				min1=pos1;
				pos1--;
			}else{
				min1 = pos2;
				pos2++;
			}

		}else{
			min1 = pos2;
			pos2++;
		}

		if (pos1>=0)
		{
			if (count[pos1]<count[pos2])
			{
				min2=pos1;
				pos1--;
			}else{
				min2=pos2;
				pos2++;
			}
			
		}else{
			min2 = pos2;
			pos2++;
		}
		//printf("count[%lld]=%lld count[%lld]=%lld\n",min1,count[min1],min2,count[min2]);
		count[vocab_size + a]=count[min1]+count[min2];
		//printf("count[%lld]=%lld\n",vocab_size+a,count[vocab_size+a]);
		parent_node[min1]=vocab_size+a;
		parent_node[min2]=vocab_size+a;
		binary[min2]=1;
		//printf("binary[%lld]=%lld\n",min2,binary[min2]);			
	}
	//for (i = 0; i < 2*vocab_size-1; ++i) printf("%lld ",binary[i]);
	//for (i = 0; i < 2*vocab_size-1; ++i) printf("i=%lld,parent_node:%lld\n",i,parent_node[i]);
	
	
	for (a = 0; a < vocab_size; ++a)
	{
		b=a;//b从叶节点扫描至根节点
		k=0;
		while(1){
			code[k] = binary[b];
			point[k] = b;
			k++;
			b=parent_node[b];
			if (b==vocab_size*2-2) break;
		}
		vocab[a].codelen=k;//huffman编码长度
		vocab[a].point[0]=vocab_size*2-2;
		for (b = 0; b < k; ++b)//逆序处理
		{
			vocab[a].code[k-b-1]=code[b];
			vocab[a].point[k-b]=point[b];
		}

		//printf("vocab[%lld].cn=%lld\n",a,vocab[a].cn);
		//printf("vocab[%lld].codelen=%d\n",a,vocab[a].codelen);
		//for ( i = 0; i < k; ++i) printf("vocab[%lld].code=%d\n",a,vocab[a].code[i]);
		//for ( i = 0; i < k+1; ++i) printf("vocab[%lld].point=%d\n",a,vocab[a].point[i]);
		
		
	}
	
	free(count);
	free(binary);
	free(parent_node);
	
	//output
	for (a = 0; a < vocab_size; ++a)
	{
		printf("vocab[%lld].cn=%lld\n",a,vocab[a].cn);
		//printf("vocab[%lld].codelen=%d\n",a,vocab[a].codelen);
		printf("code: ");
		for ( i = 0; i < vocab[a].codelen; ++i) printf("%d ",vocab[a].code[i]);
		printf("\n");
		//printf("point: ");
		//for ( i = 0; i < vocab[a].codelen+1; ++i) printf("%d ",vocab[a].point[i]);
		//printf("\n");
	}
	
	
}

