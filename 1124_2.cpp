#include <iostream>
#include <string>
using namespace std;
string getRoot(string s){
	int v = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		v += s[i]-'0';
	}
	int t=v,tmp;
	string res;
	res.resize(0);
	while(t>0){
		tmp=t%10;
		res.push_back('0'+tmp);
		t/=10;
	}
	if (res.size()==1)
		return res;
	else
		return getRoot(res);
}

int main(){
	//freopen("input.txt","r",stdin);
	string s;
	while(cin>>s&&s!="0"){
		cout<<getRoot(s)<<endl;
	}
	return 0;
}