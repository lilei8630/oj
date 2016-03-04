#include <iostream>  
using namespace std;  
  
int main()  
{  
    freopen("input.txt","r",stdin);
    double a,sum;  
    while(cin >> a)  
    {  
        sum = 0;  
        sum+=a;  
        int n = 11;  
        while(n--)  
        {  
            cin >> a;  
            sum+=a;  
        }  
        cout << "$" << sum/12.0 << endl;  
        cout << sum<<endl;
    }  
  
    return 0;  
}  