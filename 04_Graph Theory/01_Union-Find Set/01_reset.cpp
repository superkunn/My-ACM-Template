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
