struct DSU{
    int p[MAXN],sz[MAXN];
    int Back[MAXN][2];
    int cnt;
    void init(int n){rep(i,0,n)p[i]=i,sz[i]=1;cnt=0;}
    int findp(int x){return x==p[x]?x:findp(p[x]);}
    void unite(int x,int y){
        x=findp(x);y=findp(y);if(x==y)return;
        if(sz[x]>sz[y])swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
        Back[++cnt][0]=x;
        Back[++cnt][1]=y;
    }
    void save(){cnt=0;}
    void Cancel(){
        while(cnt){
            int x=Back[cnt][0];
            int y=Back[cnt][1];
            p[x]=x;
            sz[y]-=sz[x];
            cnt--;
        }
    }
    bool same(int x,int y){return findp(x)==findp(y);}
}dsu;


namespace DSU2 {
  const static int MAXN = 100000 + 10;
  int fa[MAXN], ds[MAXN], rk[MAXN];
  int S[MAXN], top;
  void init(int n) {
    for (int i = 1; i <= n; ++ i) {
      fa[i] = i, rk[i] = ds[i] = 0;
    }
    top = 0;
  }
  int dis(int x) {
    int r(0);
    for (; x != fa[x]; x = fa[x]) r ^= ds[x];
    return r;
  }
  int get(int x) {
    while (x != fa[x]) x = fa[x];
    return fa[x];
  }
  void merge(int x, int y, int d) {
    x = get(x); y = get(y);
    if (x == y) return;
    if (rk[x] > rk[y]) std::swap(x, y);
    if (rk[x] == rk[y]) ++ rk[y], S[++ top] = -y;
    fa[x] = y; ds[x] = d; S[++ top] = x;
  }
  void restore(int ed) {
    for (; top > ed; -- top) {
      if (S[top] < 0) -- rk[-S[top]];
      else fa[S[top]] = S[top], ds[S[top]] = 0;
    }
  }
}
