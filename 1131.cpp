#include <stdio.h>
int list[110];
int dp[2][110];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&list[i]);
        for(i=1;i<=n;i++)
        {
            int tmax=1;
            for(j=1;j<i;j++)
            
                if(list[j]<list[i])
                    tmax=max(tmax,dp[0][j]+1);
            
            dp[0][i] = tmax;
        }

        for(i=n;i>=1;i--)
        {
            int tmax=1;
            for(j=n;j>i;j--)
                if(list[j]<list[i])
                    tmax = max(tmax,dp[1][j]+1);
            dp[1][i]=tmax;
        }
        for(int i=1;i<=n;i++){
            printf("%d ",dp[0][i]);
            
        }
        printf("\n");
        for(int i=1;i<=n;i++)
        {
            printf("%d ",dp[1][i]);
        }
        printf("\n");

        int ans=1;
        for(i=1;i<=n;i++)
            for(j=n;j>i;j--)
                if(ans<dp[0][i]+dp[1][j]&&list[i]!=list[j])
                    ans=dp[0][i]+dp[1][j];
        printf("%d\n",n-ans);

    }
}
