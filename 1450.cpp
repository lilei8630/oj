#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>

using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	int n;
	while(scanf("%d",&n)!=EOF){
		if (n==0)
			break;
		set<string> st;
		map<string,string> mp;
		string a,b;
		for (int i = 0; i < n; ++i)
		{
			cin>>a>>b;
			st.insert(a);
			st.insert(b);
			mp[b]=a;
		}
		set<string>:: iterator iter;
		int cnt=0;
		for (iter= st.begin(); iter != st.end(); ++iter)
		{
			if (!mp[*iter].length())
			{
				cnt++;
			}
		}
		if (cnt==1)
		{
			printf("YES\n");
		}else
			printf("NO\n");

	}
	return 0;
}