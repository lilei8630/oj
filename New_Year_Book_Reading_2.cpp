#include<iostream>  
#include<cstdio>  
#include<algorithm>  
#include<cstring>  
#include<string>  
#include<cmath>  
#include<cstdlib>  
using namespace std;  
  
int rem[500];  
int main()  
{  
    freopen("0input.txt","r",stdin);
    int i,j,n,m,p=0,sum=0;  
    int w[501],b[1001];  
    int tmp[501];  
    scanf("%d %d",&n,&m);  
    for(i=0;i<n;i++)  
    {  
        scanf("%d",&w[i]);  
    }  
    for(i=0;i<m;i++)  
    {  
        scanf("%d",&b[i]);  
        b[i]--;  
        if(rem[b[i]]==0)  
        {  
            tmp[p++]=b[i];  
            rem[b[i]]=1;  
        }  
    }  
    sum=0;    
    for (int i = 1; i <= n; ++i) printf("%d ",tmp[i]);
            printf("res:%d \n",sum);
    for(i=0;i<m;i++)  
    {  
        p=0;  
        while(tmp[p]!=b[i])  
        {  
            sum+=w[tmp[p]];  
            p++;  
        }  
        for(j=p;j>=1;j--)  
            tmp[j]=tmp[j-1];  
        tmp[0]=b[i];  
        for (int i = 1; i <= n; ++i) printf("%d ",tmp[i]);
            printf("res:%d \n",sum);
    }  
    printf("%d\n",sum);  
    return 0;  
}  