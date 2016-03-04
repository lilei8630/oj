#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
	
	//freopen("input.txt","r",stdin);
	
	string a,b;
	
	int n;
	
	while(cin>>n&&n){
	
		int indegree[2000]={0};
	
		map<string,int> sm;
	
		int ix=0,aix,bix;
	
		while(n--){
	
			cin>>a>>b;
	
			if (sm.find(a)!=sm.end())
			{
				aix=sm[a];
			}else{
	
				sm[a]=ix++;
			}

			if (sm.find(b)!=sm.end())
			{
	
				bix=sm[b];

			}else{
	
				bix=ix;
	
				sm[b]=ix++;
			}
	
			++indegree[bix];
		}
		int count = 0;
		for (int i = 0; i < ix; ++i)
		{
			if (indegree[i]==0)
			{
				++count;
			}
		}
		cout<<(count==1?"Yes":"No")<<endl;
	}
	return 0;
}