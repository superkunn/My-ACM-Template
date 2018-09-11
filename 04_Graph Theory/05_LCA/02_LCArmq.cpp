#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define clr(a,x) memset(a,x,sizeof(a))
#define MAXLOGN 22
const int MAXV=250000+100;
int tot;
int head[MAXV];
struct Edge{
    int v,nxt;
    Edge(){}
    Edge(int v,int nxt):v(v),nxt(nxt){}
}edge[MAXV<<1];
void init(){
    tot=0;
    clr(head,-1);
}
void add_edge(int u,int v){
    edge[tot]=Edge(v,head[u]);
    head[u]=tot++;
}
int st[MAXLOGN][2*MAXV];
vector<int> G[MAXV];
int vs[MAXV*2-1];
int depth[MAXV*2-1];
int id[MAXV];
void dfs(int v,int p,int d,int &k){
    id[v]=k;
    vs[k]=v;
    depth[k++]=d;
    for(int i=head[v];~i;i=edge[i].nxt){
        if(edge[i].v!=p){
            dfs(edge[i].v,v,d+1,k);
            vs[k]=v;
            depth[k++]=d;
        }
    }
}
int getMin(int x, int y){
    return depth[x]<depth[y]?x:y;
}
void rmq_init(int n){
    for(int i=1;i<=n;++i) st[0][i]=i;
    for(int i=1;1<<i<n;++i)
        for(int j=1;j+(1<<i)-1<=n;++j)
            st[i][j]=getMin(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
void lca_init(int V){
    int k=0;
    dfs(0,-1,0,k);
    rmq_init(V*2-1);
}
int query(int l, int r){
    int k=31-__builtin_clz(r-l+1);
    return getMin(st[k][l],st[k][r-(1<<k)+1]);
}
int lca(int u,int v){
    if(u==v) return u;
    return vs[query(min(id[u],id[v]),max(id[u],id[v]))];
}
int dis(int u,int v){
    return depth[id[u]]+depth[id[v]]-2*depth[id[lca(u,v)]];
}
struct DSU{
    int p[MAXV];
    void init(int n){rep(i,0,n)p[i]=i;}
    int findp(int x){return x==p[x]?x:p[x]=findp(p[x]);}
    bool same(int x,int y){return findp(x)==findp(y);}
    bool unite(int x,int y){x=findp(x);y=findp(y);p[x]=y;}
}dsu;
struct node{
    int u,v,c;
    node(){}
    node(int u,int v,int c):u(u),v(v),c(c){}
}no[MAXV<<1];
bool cmp(node a,node b){
    return a.c>b.c;
}
int main(){
    int N,M;
    scanf("%d%d",&N,&M);
    int index=0;
    for(int i=0;i<N*M;i++){
        int r=i/M;
        int c=i%M;
        for(int j=0;j<2;j++){
            char op[4];
            int x;
            scanf("%s%d",op,&x);
            if(op[0]=='X')continue;
            if(op[0]=='R'){
                if(c==M-1)continue;
                no[++index]=node(i,i+1,x);
            }else{
                if(r==N-1)continue;
                no[++index]=node(i,i+M,x);
            }
        }
    }
    sort(no+1,no+1+index,cmp);
    init();
    int V=N*M;
    dsu.init(V);
    for(int i=1;i<=index;i++){
        if(!dsu.same(no[i].u,no[i].v)){
            add_edge(no[i].u,no[i].v);
            add_edge(no[i].v,no[i].u);
            dsu.unite(no[i].u,no[i].v);
        }
    }
    lca_init(V);
    int q;
    scanf("%d",&q);
    while(q--){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        x1--;
        y1--;
        x2--;
        y2--;
        int x=x1*M+y1;
        int y=x2*M+y2;
        printf("%d\n",dis(x,y));
    }
    return 0;
}
