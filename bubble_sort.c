#include <stdio.h>
void bubble_sort(long list[], long n)
{
	long c,d,t;
	
	int swap;
	for (c = 0; c < (n-1); c++)
	{ 	swap = 0;
		for (d = 0; d < n-c-1; d++)
		{
			if (list[d]>list[d+1])
			{
				t = list[d];
				list[d] = list[d+1];
				list[d+1] = t;
				swap = 1;
			}
		}
		if (!swap)
			break;
	}
}
int main(){
	long list[]=
	{134235,2357,46765,454756,436,6547,4653,1244,
		35684,624,4345,123435,558998,2996,345679,35675,451278,6768,343,236354};
	long n = sizeof(list)/sizeof(long);
	bubble_sort(list,n);
	long c;
	for (c = 0; c < n; ++c)
		printf("%ld \n",list[c]);
	return 0;
}







