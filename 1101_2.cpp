#include <stdio.h>
int main()
{
  freopen("input.txt","r",stdin);
    int i,j,k,a[100];
    char x;
    while(scanf("%d",&k)!=EOF)
    {
       a[0]=0;
       i=0;
       a[++i]=k;
        while(scanf("%c",&x)!=EOF&&(x=='+'||x=='-'||x=='*'||x=='/'))
        {
          scanf("%d",&k);
           if(x=='+')
             a[++i]=k;
           else if(x=='-')
             a[++i]=-1*k;
           else if(x=='*')
             a[i]*=k;
           else
             a[i]/=k;
        }
        for(j=1;j<=i;j++)
           a[0]+=a[j];
        printf("%d\n",a[0]);
    }
    return 0;
}