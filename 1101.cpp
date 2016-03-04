#include <stack>
#include <stdio.h>
using namespace std;
char str[220]; //保存表达式字符串
/*
优先级矩阵，记人为添加在表达式首位的标记运算符为0号，
＋为1号，－为2号，＊为3号，/为4号，若mat[i][j]==1
则表示i号运算符优先级大于j号。
*/
int mat[][5]={
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0,
};

stack<int> op;	//运算符栈
stack<int> in;//数字栈
/*
获得表达式中下一个元素的函数，若函数结束运行时，引用变量reto为true，则表示该元素
为一个运算符，其编号保存在饮用变量retn中；否则，表示该元素为一个数字，其值保存在
引用变量retn中，引用变量i表示遍历到的字符串的下标。
*/
void getOp(bool &reto,int &retn,int &i){
	if (i==0&&op.empty()==true)//初始时将0号运算符压栈
	{
		reto=true;
		retn=0;
		return;
	}
	if (str[i]==0)//字符串扫描结束时，将0号运算符压栈
	{
		reto=true;
		retn=0;
		return;
	}

	if (str[i]>='0'&&str[i]<='9')//当为数字时，将reto置为false
	{
		reto = false;
	}
	else{			//其他情况均为运算符
		reto=true;
		if (str[i]=='+')
		{
			retn=1;
		}else if (str[i]=='-')
		{
			retn=2;
		}else if (str[i]=='*')
		{
			retn=3;
		}else if (str[i]=='/')
		{
			retn=4;
		}
		i++;
		return;
	}
	retn=0;
	for (; str[i] !='+'&&str[i] !='-'&&str[i] !='*'&&str[i] !='/'&&str[i]!=0; ++i)
	{
		retn*=10;
		retn+=str[i]-'0';
	}

	return ;
}
int main(){
	//char str[200];
	freopen("input.txt","r",stdin);
	while(scanf("%s",str)!=EOF){
		//puts(str);
		bool retop;
		int retnum;
		int idx=0;
		while(!op.empty()) op.pop();
		while(!in.empty()) in.pop();
		while(true){
			getOp(retop,retnum,idx);
			//printf("idx:%d,retop:%d,retnum:%d\n",idx,retop,retnum);
			if (retop==false) //操作数进栈
			{
				in.push(retnum);
			}else{
				double tmp;
				if (op.empty()==true||mat[retnum][op.top()]==1)//运算符优先级高的要进栈
				{
					op.push(retnum);
				}else{
					while(mat[retnum][op.top()]==0){
						int ret=op.top();
						op.pop();
						int  b=in.top();
						in.pop();
						int  a = in.top();
						in.pop();
						if (ret==1)
						{
							tmp=a+b;
						}
						else if(ret ==2) tmp=a-b;
						else if(ret ==3) tmp=a*b;
						else tmp=a/b;
						in.push(tmp);
					}
					op.push(retnum);
				}
			}
			if (op.size()==2&&op.top()==0)
			{
				break;
			}

		}
		printf("%d\n",in.top());

	}
	return 0;
}
