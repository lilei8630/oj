#include <iostream>
#include <string>

using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	string str;
	string str2("ru");
	while(cin>>str)
	{
		int len=str.size();
		int b;               //domain后第一个ru的位置
		int k=str.find(str2);//第一个ru的位置
		//cout<<"k="<<k<<endl;
		if (((k==4)&&str.at(0)=='h')||((k==3)&&str.at(0)=='f'))
		{
			//cout<<"k+2="<<k+2<<endl;
			b=str.find(str2,k+2);//由于domain非空，所以需要找到第二个ru
			//cout<<"b2="<<b<<endl;
		}else{
			b=k;
		}

		if (b+2<len)
		{
			str.insert(b+2,"/");
		}
		str.insert(b,".");
		if (str.at(0)=='f')
		{
			str.insert(3,"://");
			cout<<str<<endl;
		}
		else if (str.at(0)=='h')
		{
			str.insert(4,"://");
			cout<<str<<endl;
		}
		

	}
	return 0;
}