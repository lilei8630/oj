#include <cstdio>
#include <cstring>
bool isprime[40001];
int prime[10000];
int primenum;
//约数定理
int  ispri()
{
    isprime[0]=isprime[1]=1;
    for (int i = 2; i <=200 ; ++i)
    {
        if (!isprime[i])
        {
            for (int j = i*i; j <= 40000; j+=i)
            {
                isprime[j]=1;
            }
        }
        
    }
    primenum=0;
    for (int j = 2; j <= 40000; j++)
    {
        if (!isprime[j])
        {
            prime[primenum++]=j;
        }
    }
    return 0;
}

int main(){
    ispri();
    //freopen("input.txt","r",stdin);
    int T,x;
    while(scanf("%d",&T)!=EOF)
    {
        if (T==0)
        {
            break;
        }

        for (int i = 0; i < T; ++i)
        {
            scanf("%d",&x);
            int sum = 1;
            int num = 0;
            while(num<primenum)
            {
                if (x<40000&&isprime[x]==0)
                {
                    x=1;
                    sum*=2;
                    break;
                }
                if (x==1)
                    break;
                int rnum=0;
                while(x%prime[num]==0)
                {
                    x=x/prime[num];
                    rnum++;
                }
                num++;
                sum*=(rnum+1);
            }
            if (x>1)
            {
                sum*=2;
            }
            printf("%d\n",sum);

        }

    }
    return 0;
}    
