#include <iostream>
#include <string>
using namespace std;
//定义函数指针pf
int (*pf)(const int &,const int &); 
//定义函数指针类型cmpFun
typedef int (*cmpFun)(const int&,const int&);
//函数指针作为参数
int plusFun(int&,int&,int(const int&,const int&));
int plusFun(int&,int (*)(const int&,const int&));
//函数指针作为返回值
int (*retFunPointer(int))(const int&,const int&);

//具体函数
int intCompare(const int &aInt,const int & bInt)
{
	if (aInt==bInt) return 0;
	if (aInt>bInt)  return 1;
	else return -1;
}
//函数指针作为参数
int plusFun(int& aInt,int& bInt,int paf(const int&,const int&))
{
	int cInt = 2;
	int dInt = 1;
	return aInt+bInt+paf(cInt,dInt);
}
//函数指针作为参数
int plusFun(int & aInt,int(*paf2)(const int&,const int &))
{
	int bInt=1;
	int cInt=2;
	return aInt+paf2(bInt,cInt);
}
//函数指针作为返回值
int (*retFunPointer(int aInt))(const int&,const int&)
{
	cout<<aInt<<endl;
	return pf;
}

int main(){
	int aInt=1;int bInt=2;
	pf=intCompare;  //使用pf
	if (pf(aInt,bInt)==0){
		cout<<"two integers are equal"<<"."<<endl;
	}else if (pf(aInt,bInt)>0){
		cout<<aInt<<"is greater than"<<bInt<<"."<<endl;
	}else{
		cout<<aInt<<"is less than"<<bInt<<"."<<endl;
	}
	//用函数指针类型cmpFun声明并初始化一个函数指针pf2
	cmpFun pf2= intCompare; //使用pf2
	if (pf(aInt,bInt)==0){
		cout<<"two integers are equal"<<"."<<endl;
	}else if (pf(aInt,bInt)>0){
		cout<<aInt<<"is greater than"<<bInt<<"."<<endl;
	}else{
		cout<<aInt<<"is less than"<<bInt<<"."<<endl;
	}
	//函数指针作为参数
	int aaInt = 3;int bbInt = 4;
	cout<<plusFun(aaInt,bbInt,pf)<<endl;
	cout<<plusFun(aaInt,pf2)<<endl;
	//函数指针作为返回值，retFunPointer返回一个cmpFun类型的函数指针
	cmpFun pf3 = retFunPointer(aaInt);
	int result = pf3(aaInt,bbInt);
	cout<<result<<endl;
	return 0;
}