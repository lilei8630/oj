#include <stdio.h>
void selection_sort(long list[],long n)
{
	long i,j,t;
	long iMin;
	for(j=0;j<n-1;j++)
	{
		iMin = j;
		for ( i = j+1; i < n; ++i)
		{
			if (list[i] < list[iMin])
			{
				iMin = i;
			}
		}
		if (iMin !=j)
		{
			t = list[j];
			list[j] = list[iMin];
			list[iMin] = t;
 		}

	}
}

int main(){
	long list[] = {123,35,24,353,456,4576,87,908,675,4653,42,354,
		45,67,8968,574,635,2,4,16};
	long  n = sizeof(list)/sizeof(long);
	selection_sort(list,n);
	for (long i = 0; i < n; ++i)
		printf("%ld ", list[i]);
}