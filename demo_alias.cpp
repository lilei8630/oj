#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gsl/gsl_rng.h>
// Parameters for edge sampling
long long *alias;
double *prob;
double *edge_weight;
long long num_edges,i;
const gsl_rng_type * gsl_T;
gsl_rng * gsl_r;

void InitAliasTable()
{
	alias = (long long *)malloc(num_edges*sizeof(long long));
	prob = (double *)malloc(num_edges*sizeof(double));
	if (alias == NULL || prob == NULL)
	{
		printf("Error: memory allocation failed!\n");
		exit(1);
	}

	double *norm_prob = (double*)malloc(num_edges*sizeof(double));
	long long *large_block = (long long*)malloc(num_edges*sizeof(long long));
	long long *small_block = (long long*)malloc(num_edges*sizeof(long long));
	if (norm_prob == NULL || large_block == NULL || small_block == NULL)
	{
		printf("Error: memory allocation failed!\n");
		exit(1);
	}

	double sum = 0;
	long long cur_small_block, cur_large_block;
	long long num_small_block = 0, num_large_block = 0;

	for (long long k = 0; k != num_edges; k++) sum += edge_weight[k];//统计所有边的权重和
	for (long long k = 0; k != num_edges; k++) norm_prob[k] = edge_weight[k] * num_edges / sum;//每个边占平均权重多少

	for (long long k = num_edges - 1; k >= 0; k--)//标准化权重分为两组
	{
		if (norm_prob[k]<1)
			small_block[num_small_block++] = k;
		else
			large_block[num_large_block++] = k;
	}
	//printf("num_small_block:%lld num_large_block:%lld\n",num_small_block,num_large_block);

	while (num_small_block && num_large_block)
	{
		cur_small_block = small_block[--num_small_block];  //cur_small_block是当前小边序号
		cur_large_block = large_block[--num_large_block];  //cur_large_block是当前大边的序号
		//printf("cur_small_block:%lld cur_large_block:%lld \n",cur_small_block,cur_large_block);
		prob[cur_small_block] = norm_prob[cur_small_block];//将归一化概率赋给prob数组
		alias[cur_small_block] = cur_large_block;          //当前小边对应的别名表的值是当前大边的序号
		//norm_prob[cur_large_block] = norm_prob[cur_large_block]-(1-norm_prob[cur_small_block]);
		norm_prob[cur_large_block] = norm_prob[cur_large_block] + norm_prob[cur_small_block] - 1;
		//printf("norm_prob[%lld]:%lf\n",cur_large_block,norm_prob[cur_large_block]);
		if (norm_prob[cur_large_block] < 1)
			small_block[num_small_block++] = cur_large_block;
		else
			large_block[num_large_block++] = cur_large_block;
		//printf("num_small_block:%lld num_large_block:%lld\n",num_small_block,num_large_block);
	}

	while (num_large_block) prob[large_block[--num_large_block]] = 1;
	while (num_small_block) prob[small_block[--num_small_block]] = 1;

	free(norm_prob);
	free(small_block);
	free(large_block);
}

long long SampleAnEdge(double rand_value1, double rand_value2)//???
{
	long long k = (long long)num_edges * rand_value1;
	return rand_value2 < prob[k] ? k : alias[k];
}

int main()
{

	FILE * fin;
	i=0;
	num_edges=0;
	char str[1000];
	double weight;
	long long curedge=-1;
	//对gsl_r进行初始化
	gsl_rng_env_setup();
	gsl_T = gsl_rng_rand48;
	gsl_r = gsl_rng_alloc(gsl_T);
	gsl_rng_set(gsl_r, 314159265);

	fin=fopen("input.txt","r");
	while (fgets(str, sizeof(str), fin)) num_edges++;
	fclose(fin);
	edge_weight = (double *)malloc(num_edges*sizeof(double));
	fin=fopen("input.txt","r");
	for (i = 0; i != num_edges; ++i)
	{
		fscanf(fin,"%lf",&weight);
		edge_weight[i]=weight;
	}

	
	//printf("num_edges:%lld\n",num_edges);
	InitAliasTable();
	for (int i = 0; i != num_edges; ++i) printf("%lf ", prob[i]);
	printf("\n");	
	for (int i = 0; i != num_edges; ++i) printf("%lld ", alias[i]);
	printf("\n");

	for (int k = 0; k < 10; ++k)
	{
		curedge = SampleAnEdge(gsl_rng_uniform(gsl_r), gsl_rng_uniform(gsl_r));	
		printf("sample curedge:%lld\n",curedge);
	}
	
	
}
































