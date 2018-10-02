ll inv(ll a,ll m){
    ll x,y;
    ll d=exgcd(a,m,x,y);
    return d==1?(x+m)%m:-1;
}
ll inv(ll a,ll m){
    return pow_mod(a,m-2,m);
}
int p=37;
inv[1]=1;
for(int i=2;i<=40;i++){
    inv[i]=(p-(p/i))*inv[p%i]%p;
}
//fact invfact
int fact[MAXN];
int invfact[MAXN];
ll pow_mod(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}
ll fun(ll n,ll m){
    return (1LL*fact[n]*invfact[m])%MOD*invfact[n-m]%MOD;
}
int n=100000;
fact[0]=1;
for(int i=1;i<=n;i++){
    fact[i]=1LL*fact[i-1]*i%MOD;
}
invfact[n]=pow_mod(fact[n],MOD-2);
for(int i=n;i>=1;i--){
    invfact[i-1]=1LL*invfact[i]*i%MOD;
}
