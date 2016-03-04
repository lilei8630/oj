#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
 freopen("input.txt","r",stdin);
 string str,_str = "WUB";
 cin>>str;
 string::size_type pot;
 str += _str;  
 int size = str.size();
 vector<string>result;
 
 for(int i = 0;i < size;i ++)
 {
  pot = str.find(_str,i);
  if(pot < size)
  {
   string s = str.substr(i,pot - i);
   if(s != "") result.push_back(s); //判断是否有连续
   i = pot + _str.size() - 1; 
  }
 }
 
 for(int i = 0;i < result.size() - 1;i ++)
  cout<<result[i]<<" ";
  cout<<result[result.size() - 1]<<endl;
 
 return 0;
}