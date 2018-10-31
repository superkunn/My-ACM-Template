const int MAXN=2000+10;
int a[105][MAXN];
int f[MAXN],ff[MAXN];
int m,n;
struct node{
    int x,y,visy,v;
    node(){}
    node(int x,int y,int visy,int v):
        x(x),y(y),visy(visy),v(v){}
};
bool operator<(const node &lhs,const node &rhs){
    return lhs.v>rhs.v;
}
priority_queue<node> pque;
void gao(int x){
    while(!pque.empty())pque.pop();
    pque.push(node(1,1,0,f[1]+a[x][1]));
    rep(i,1,n){
        node now=pque.top();
        pque.pop();
        ff[i]=now.v;
        if(i==n)break;
        int w1=now.x;
        int w2=now.y;
        if(now.visy==1){
            if(w2!=n)pque.push(node(w1,w2+1,1,f[w1]+a[x][w2+1]));
        }else{
            if(w1!=n)pque.push(node(w1+1,w2,0,f[w1+1]+a[x][w2]));
            if(w2!=n)pque.push(node(w1,w2+1,1,f[w1]+a[x][w2+1]));
        }
    }
    rep(i,1,n)f[i]=ff[i];
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        while(!pque.empty())pque.pop();
        scanf("%d%d",&m,&n);
        rep(i,1,m){
            rep(j,1,n){
                scanf("%d",&a[i][j]);
            }
            sort(a[i]+1,a[i]+1+n);
        }
        rep(i,1,n)f[i]=a[1][i];
        rep(i,2,m){
            gao(i);
        }
        rep(i,1,n)printf("%d%c",f[i]," \n"[i==n]);
    }
    return 0;
}
