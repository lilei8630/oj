#include <iostream> 
#include <cstdio> 
#include <cmath> 
using namespace std; 
 
typedef long long int64; 
int64 n, sx; 
 
int64 digitSum(int64 n){ 
    cout<<2132<<endl;
    int64 sum=0; 
    while(n){ 
        sum += n%10; 
        n/=10; 
    } 
    return sum; 
} 
 
int main(){ 
    while(cin >> n){ 
        cout<<digitSum(9999999)<<endl;
        int64 x=1,ans=-1; 
         
        for(int64 i=1; i<=100; ++i){ 
            int64 tmp = i*i/4+n; 
 
            x = sqrt(tmp)-i/2;  
 
            sx = digitSum(x); 
            if(x*x+sx*x-n==0){ 
                ans=x; 
                break; 
            } 
        } 
        cout << ans << endl; 
    } 
    return 0; 
} 

 