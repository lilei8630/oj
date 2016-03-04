#include <iostream>
#include <string>
#include <map>
using namespace std;
string str;
string Num[10]={"zero","one","two","three","four",
    "five","six","seven","eight","nine"};
map<string,int> Q;

void init()
{
    for(int i=0;i<10;i++)
        Q[Num[i]]=i;
}
int main()
{
    int i,a,b,len,flag;
    init();
    while(getline(cin,str))
    {
        a=b=flag=0;
        len=str.size();
        for(i=0;i<len;i++)
        {
            string op;
            while(str[i]!=' '&&i<len)
            {
                op+=str[i];
                i++;
            }
            if(op[0]=='+'||op[0]=='=')
            {
                flag=1;
                continue;
            }
            if(!flag)
                a=a*10+Q[op];
            else
                b=b*10+Q[op];

        }
        if(a==0&&b==0)
            break;
        else
            cout<<a+b<<endl;
    }
    return 0;
}

