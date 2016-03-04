#include <iostream>
#include <string>
using namespace std;
int main(){
	//freopen("input.txt","r",stdin);
	string str;
	
	while(cin>>str){
		int len;
		long long tmp=0;
		long long c=1;
		int buf[200];
		len=str.size();
		for (int i = len-1; i >= 0; i--)
		{
			tmp+=(str[i]-'0')*c;
			c*=10;
		}
		int size=0;
		do{
			buf[size++]=tmp%2;
			tmp/=2;

		}while(tmp);
		for (int i = size-1; i >= 0; i--)
		{
			cout<<buf[i];
			
		}
		cout<<endl;
	}
}