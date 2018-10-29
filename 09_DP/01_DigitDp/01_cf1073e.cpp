const ll MOD=998244353;
ll l,r;
int k;
pair<ll,ll> dp[22][1<<11];
bool vis[22][1<<11];
ll base[22];
int bt[22];
int fun(int x){
    int res=0;
    while(x){
        res++;
        x-=x&-x;
    }
    return res;
}
pair<ll,ll> dfs(int pos,int pre,bool limit,bool lead){
    if(pos==0)return fun(pre)<=k?mp(1,0):mp(0,0);
    if(!limit&&!lead&&vis[pos][pre])return dp[pos][pre];
    int u=limit?bt[pos]:9;
    pair<ll,ll> res=mp(0,0);
    for(int i=0;i<=u;i++){
        int now=pre;
        if(lead&&i==0){
            now=0;
        }else{
            now=pre|(1<<i);
        }
        pair<ll,ll> tmp=dfs(pos-1,now,limit&&i==bt[pos],lead&&i==0);
        res.first=(res.first+tmp.first)%MOD;
        ll w=1LL*i*base[pos]%MOD;
        w=(w*tmp.first)%MOD;
        res.second=(res.second+tmp.second+w)%MOD;
    }
    if(!limit&&!lead)dp[pos][pre]=res,vis[pos][pre]=true;
    return res;
}
ll gao(ll x){
    int pos=0;
    while(x){
        bt[++pos]=x%10;
        x/=10;
    }
    return dfs(pos,0,true,true).second;
}
int main(){
    base[1]=1;
    for(int i=2;i<=21;i++){
        base[i]=base[i-1]*10%MOD;
    }
    scanf("%I64d%I64d%d",&l,&r,&k);
    printf("%I64d",(gao(r)-gao(l-1)+MOD)%MOD);
    return 0;
}
