// $a_{i}=\sum_{i=1}^{x}d_{i}$\\
// $\sum_{i=1}^{x}a_{i}=\sum_{i=1}^{x}\sum_{j=1}^{i}d_{j}=\sum_{i=1}^{x}(x-i+1)d_{i}$\\
// $\sum_{i=1}^{x}a_{i}=(x+1)\sum_{i=1}^{x}d_{i}-\sum_{i=1}^{x}d_{i}\times&space;i$\\
const int MAXN=1e5+5;
int n,q,x,y,z;
long long c1[MAXN],c2[MAXN];
void add(int x,int y){
    for(int i=x;i<=n;i+=i&(-i))c1[i]+=y,c2[i]+=1LL*x*y;
}
ll sum(int x){
    ll ans(0);
    for(int i=x;i;i-=i&(-i))ans+=1LL*(x+1)*c1[i]-c2[i];
    return ans;
}
char op[5];
int work(){
    scanf("%d%d",&n,&q);
    int a1,a2;
    a1=0;
    rep(i,1,n){
        scanf("%d",&a2);
        add(i,a2-a1);
        a1=a2;
    }
    while(q--){
        scanf("%s",op);
        if(op[0]=='Q'){
            scanf("%d%d%d",&x,&y,&z);
            printf("%lld\n",sum(y)-sum(x-1));
        }else{
            scanf("%d%d%d",&x,&y,&z);
            add(x,z);
            add(y+1,-z);
        }
    }
    return 0;
}
