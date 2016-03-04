#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	string str;
	string _str("WUB");
	vector<string> result;
	int i;
	int pos;
	int size;
	while(cin>>str){
		result.clear();
		str+=_str;
		size=str.size();
		for (i = 0; i < size; ++i)
		{
			pos=str.find(_str,i);
			if (pos<size)
			{
				string s=str.substr(i,pos-i);
				if (s!="")
				{
					result.push_back(s);
				}
				i=pos+_str.size()-1;
			}
			
		}
		for (i = 0; i < result.size()-1; ++i)
			cout <<result[i]<<" ";
		cout<<result[result.size()-1]<<endl;

	}
	return 0;
}