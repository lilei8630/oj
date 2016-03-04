#include <stdio.h>
#include <stack>
using namespace std;
int main()
{
	stack<int> s;
	while(!s.empty()) s.pop();
	printf("s.top():%d\n",s.top());
}
