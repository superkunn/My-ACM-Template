//hdu 2586
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
int t,f[MAXV][22],d[MAXV];
ll dist[MAXV];
void bfs(){
    queue<int> que;
    que.push(1);
    d[1]=1;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        for(int i=head[u];~i;i=edge[i].nxt){
            int v=edge[i].v;
            if(d[v])continue;
            d[v]=d[u]+1;
            dist[v]=dist[u]+edge[i].w;
            f[v][0]=u;
            for(int j=1;j<=t;j++){
                    f[v][j]=f[f[v][j-1]][j-1];
            }
            que.push(v);
        }
    }
}
int lca(int x,int y){
    if(d[x]>d[y])swap(x,y);
    for(int i=t;i>=0;i--){
        if(d[f[y][i]]>=d[x])y=f[y][i];
    }
    if(x==y)return x;
    for(int i=t;i>=0;i--){
        if(f[x][i]!=f[y][i]){
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}
int main() {
	int T;
	cin>>T;
	while (T--) {
        int n,m;
		cin >> n >> m;
		t = (int)(log(n) / log(2)) + 1;
		init();
		memset(d,0,sizeof(d));
		for (int i = 1; i < n; i++) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			add_edge(x, y, z), add_edge(y, x, z);
		}
		bfs();
		for (int i = 1; i <= m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			printf("%lld\n", dist[x] + dist[y] - 2 * dist[lca(x, y)]);
		}
	}
}
