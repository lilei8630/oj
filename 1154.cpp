#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

struct edge{
    char x;
    char y;
    int cost;
    edge(char a,char b,int c){
        x = a; y = b; cost = c;
    }
};

map<char,char> fa;
vector<char> V;
vector<edge> E;
edge *p;

char find(char x){
    if (fa[x]==x) return x;
    else{
        char tmp = find(fa[x]);
        fa[x]=tmp;
        return tmp;
    }
}

bool comp(edge a,edge b){
    return a.cost<b.cost;
}

int main(int argc,char* argv[]){
    //freopen("input.txt","r",stdin);
    int N;
    while(cin>>N&&N){
        int tmp=N;
        V.clear();
        E.clear();
        char a,b;
        int n,c;
        N--;
        while(N--){
            cin>>a>>n;
            V.push_back(a);
            while(n--){
                cin>>b>>c;
                p = new edge(a,b,c);
                E.push_back(*p);
            }
        }
        V.push_back('A'+tmp);
        for(int i=0;i<V.size();i++){
            fa[V[i]] = V[i];
        }
        int cost = 0;
        sort(E.begin(),E.end(),comp);
        for(int i=0;i<E.size();i++){
            //cout<<E[i].x<<" "<<E[i].y<<" "<<E[i].cost<<endl;
            char fx,fy;
            fx = find(E[i].x);
            fy = find(E[i].y);
            if(fx!=fy){
                fa[fy] = fx;
                cost += E[i].cost;
            }
           
        }
        cout<<cost<<endl;
    }
    return 0;
}