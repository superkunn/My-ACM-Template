const int MAXV=1e5+100;
int tot;
int head[MAXV];
struct Edge{
    int v,w,nxt;
    Edge(){}
    Edge(int v,int w,int nxt):v(v),w(w),nxt(nxt){}
}edge[MAXV<<1];
void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}
void add_edge(int u,int v,int w){
    edge[tot]=Edge(v,w,head[u]);
    head[u]=tot++;
}
int fa[MAXV];
ll d[MAXV],v[MAXV],lca[MAXV],ans[MAXV];
vector<int> query[MAXV],query_id[MAXV];
void add_query(int x,int y,int id){
    query[x].push_back(y);
    query_id[x].push_back(id);
    query[y].push_back(x);
    query_id[y].push_back(id);
}
int get(int x){
    return fa[x]==x?x:fa[x]=get(fa[x]);
}
void tarjan(int x){
    v[x]=1;
    for(int i=head[x];~i;i=edge[i].nxt){
        int y=edge[i].v;
        if(v[y])continue;
        d[y]=d[x]+edge[i].w;
        tarjan(y);
        fa[y]=x;
    }
    for(int i=0;i<query[x].size();i++){
        int y=query[x][i],id=query_id[x][i];
        if(v[y]==2){
            int lca=get(y);
            ans[id]=min(ans[id],d[x]+d[y]-2*d[lca]);
        }
    }
    v[x]=2;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        init();
        for(int i=1;i<=n;i++){
            fa[i]=i;
            v[i]=0;
            query[i].clear();
            query_id[i].clear();
        }
        for(int i=1;i<n;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            add_edge(x,y,z);
            add_edge(y,x,z);
        }
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            if(x==y){
                ans[i]=0;
            }else{
                add_query(x,y,i);
                ans[i]=1<<30;
            }
        }
        tarjan(1);
        for(int i=1;i<=m;i++){
            printf("%lld\n",ans[i]);
        }
    }
    return 0;
}
