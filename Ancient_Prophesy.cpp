#include <stdio.h>
#include <string.h>
int len;
char arr[100010];
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int res[32][13][4];
int resi,resj,resk;
int day,mon,year,ans;

int num(char x){
    return (x>='0')&&(x<='9');
}

int c2i(char x){
    return x-'0';
}



int main(){
    freopen("0input.txt","r",stdin);
       while(scanf("%s",arr)!=EOF){
        memset(res,0,sizeof(res));
        len=strlen(arr);
        ans=0;
        for (int i = 0; i < len-9; ++i)
        {
            if (num(arr[i])&&num(arr[i+1])&&(!num(arr[i+2]))&&num(arr[i+3])&&num(arr[i+4])&&(!num(arr[i+5]))&&num(arr[i+6])&&num(arr[i+7])&&num(arr[i+8])&&num(arr[i+9]))
            {

                day=c2i(arr[i])*10+c2i(arr[i+1]);
                mon=c2i(arr[i+3])*10+c2i(arr[i+4]);
                year=c2i(arr[i+6])*1000+c2i(arr[i+7])*100+c2i(arr[i+8])*10+c2i(arr[i+9]);
                if (year<=2015&&year>=2013)
                    if (mon<=12&&mon>=1)
                        if (day>=1&&day<=month[mon])
                            res[day][mon][year-2012]++;
            }
        }

       
        
        for (int i = 1; i <=31; ++i)
            for (int j = 1; j <=12; ++j)
                for (int k = 1; k <=3; ++k)
                    if (res[i][j][k]>=ans)
                    {
                        ans=res[i][j][k];
                        resi=i;
                        resj=j;
                        resk=k;
                    }
        //printf("%d %d %d\n",resi,resj,resk);
         
        if (resi<10) printf("0");
        
        printf("%d-",resi);
        if (resj<10) printf("0");
        
        printf("%d-",resj);
        printf("%d\n",resk+2012);    

    }
    return 0;
}