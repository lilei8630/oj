#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

inline void Swap(int *a,int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int * Partition(int * begin,int * end){
	int pivot = *--end;
	for (int *p = begin; p!= end; ++p)
		if (*p<pivot)
			Swap(begin++,p);
	Swap(begin,end);
	return begin;
}

inline int* RandomPartition(int * begin,int * end)
{
	int * i=begin+(rand()%(end-begin));
	Swap(end-1,i);
	return Partition(begin,end);
}

int * RandomSelect(int *begin,int * end,int *d)
{
	while(1){
		if (end-begin<=1)
			return begin;
		int * mid = RandomPartition(begin,end);
		if (mid==d)	return mid;
		else if (mid>d)
			end=mid;
		else
			d=mid+(d-mid),begin = ++mid;
	}
}
int main()
{
	int a[1001];
	srand(time(0));
	for (int i = 0; i < 1001; ++i)
		a[i] = rand()%10000;
	int * p =RandomSelect(a,a+1001,a+1001/2);
	cout<<"Media:"<<*p;	
}

