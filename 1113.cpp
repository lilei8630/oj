#include <stdio.h>
#include <math.h>

int main()
{
        freopen("input.txt","r",stdin);
        int n,m,left,right;
        int count;
        int deep_n,deep_m,deep_diff;
        int i, j;

        for( scanf("%d%d",&m,&n); n!=0 && m!=0; scanf("%d%d",&m,&n) )
        {
                count = 0;
                left = right = m;

                deep_n = (int)(log(n)/log(2)+1);
                deep_m = (int)(log(m)/log(2)+1);

                deep_diff = deep_n - deep_m;

                count += (int)pow(2,deep_diff) - 1;

                for(i=1;i<=deep_diff;++i)
                {
                        left = 2*left;
                        right = 2*right+1;
                }

                if(right<=n)
                        count += right - left + 1;
                else if(left<=n)
                        count += n - left + 1;
                                
                printf("%d\n",count);
        }
    return 0;
}