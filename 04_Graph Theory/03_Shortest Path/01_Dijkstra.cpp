//cf 610 A
#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
const int MAXV=5e3+50;
const int MAXE=1e5+50;
int V;
struct edge{int to,cost;};
vector<edge> G[MAXV];
typedef pair<int,int> P;
int d[MAXV];
void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+V+1,INF);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty()){
        P t=que.top();
        que.pop();
        int v=t.second;
        if(d[v]<t.first)continue;
        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
int mat[405][405];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    V=n;
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(edge{v,1});
        G[v].push_back(edge{u,1});
        mat[u][v]=mat[v][u]=1;
    }
    dijkstra(1);
    int ans;
    if(d[n]==INF){
        printf("-1");
        return 0;
    }
    ans=d[n];
    for(int i=1;i<=n;i++)G[i].clear();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(mat[i][j]==0){
                G[i].push_back(edge{j,1});
            }
        }
    }
    dijkstra(1);
    if(d[n]==INF){
        printf("-1");
        return 0;
    }
    printf("%d",max(ans,d[n]));
    return 0;
}
