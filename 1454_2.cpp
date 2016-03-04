#include<iostream>  
#include<algorithm>  
  
using namespace std;  
const int INF = 999999999;  
struct C {  
      int weg;//重量   
      int val;//价值  
};  
C coin[501];   
int dp[10001];  
int main()  
{  
    int T;  
    cin >> T;  
    while (T--) {  
       int t, w;  
       cin >> t >> w;  
       w -= t; //实际可载重量  
       for (int i=1; i<=w; ++i)  
          dp[i] = INF;  
       dp[0] = 0;  
       int n;  
       cin >> n;  
  
       for (int i=1; i<=n; ++i) {  
           cin >> coin[i].val >> coin[i].weg;  
          for (int j=coin[i].weg; j<=w; ++j)   
              if (dp[j-coin[i].weg] != INF)  
              dp[j] = min(dp[j], dp[j-coin[i].weg] + coin[i].val);    
       }  
       if (dp[w] != INF)  
         cout << "The minimum amount of money in the piggy-bank is "  
              << dp[w] << "." << endl;  
       else  
         cout << "This is impossible." << endl;  
    }//while  
    return 0;  
}  