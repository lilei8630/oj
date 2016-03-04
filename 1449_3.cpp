#include <iostream>
#define arraysize 501
using namespace std;


int map[arraysize][arraysize];   //存储图的临界阵 
int indegree[arraysize];         //存储点的入度 
int n,m;
int main()
{
    int i,j,k;
    int p1,p2;
    freopen("input.txt","r",stdin);
    while(cin>>n>>m)
    {
        memset(map,0,sizeof(map));
        memset(indegree,0,sizeof(indegree));
        
        for(i=0;i<m;++i)
        {
            cin>>p1>>p2;
            if(!map[p1][p2])        //此处别忘了重边的判断，否则会wa 
            {
                map[p1][p2] =1;
                indegree[p2]++;     //重边的时候，如果不做处理，度数为计算错误
            }            
        }


        //拓扑排序 
        for(i=1;i<=n;++i)           //进行n次遍历，每次找出一个入度为0的节点              
        {
            for(j=1;j<=n;++j)       //遍历所有节点  
            {
                if(indegree[j]==0)    //找出入度为0的节点 
                {
                    indegree[j]--;    //度数递减，避免下次继续找到 
                    
                    if(i!=n)
                    {
                       cout<<j<<" ";
                    }
                    else
                       cout<<j<<endl;

                    for(k=1;k<=n;++k)
                    {
                        if(map[j][k]==1)   // 删除与度数为0的节点相关联的边 
                        {
                            indegree[k]--;
                        }
                    } 
                    break;
                }                             
            }
        }
    }
    return 0;
}
