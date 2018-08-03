//hdu 3062
#include<bits/stdc++.h>
using namespace std;
const int MAXV=1e4;
int V;
vector<int> G[MAXV];
vector<int> rG[MAXV];
vector<int> vs;
bool used[MAXV];
int Belong[MAXV];
void init(int x){
    V=x;
    for(int i=0;i<MAXV;i++){
        G[i].clear();
        rG[i].clear();
    }   
}
void add_edge(int u,int v){
    G[u].push_back(v);
    rG[v].push_back(u);
}
void dfs(int v){
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
        if(!used[G[v][i]]) dfs(G[v][i]);
    vs.push_back(v);
}
void rdfs(int v,int k){
    used[v]=true;
    Belong[v]=k;
    for(int i=0;i<rG[v].size();i++)
        if(!used[rG[v][i]]) rdfs(rG[v][i],k);
}
int scc(){
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=1;v<=V;v++){//from 1 to V
        if(!used[v]) dfs(v);
    }
    int k=0;
    memset(used,0,sizeof(used));
    for(int i=vs.size()-1;i>=0;i--){
        if(!used[vs[i]]) rdfs(vs[i],k++);
    }
    return k;
}
bool judge(){
    for(int i=1;i<V;i+=2){
        if(Belong[i]==Belong[i+1])return false;
    }
    return true;
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        init(2*n);
        for(int i=1;i<=m;i++){
            int a1,a2,c1,c2;
            scanf("%d%d%d%d",&a1,&a2,&c1,&c2);
            add_edge(((a1*2+c1))+1,((a2*2+c2)^1)+1);
            add_edge(((a2*2+c2))+1,((a1*2+c1)^1)+1);
        }
        scc();
        printf("%s\n",judge()?"YES":"NO");   
    }
    return 0;
}
