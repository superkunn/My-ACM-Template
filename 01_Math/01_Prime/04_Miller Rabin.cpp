ll mul_mod(ll a,ll b,ll mod){
    ll res=0;
    for(;b;b>>=1){
        if(b&1)res=(res+a)%mod;
        a=(a<<1)%mod;
    }
    return res;
}
ll pow_mod(ll a,ll b,ll mod) {
    ll res=1;
    for(;b;b>>=1){
        if(b&1)res=mul_mod(res,a,mod);
        a=mul_mod(a,a,mod);
    }
    return res;
}
bool Miller_Rabin(ll n, int s){//s is testing frequency . true -> n is prime 
    if (n == 2) return 1;
    if (n < 2 || !(n & 1)) return 0;
    int t = 0;
    ll  x, y, u = n - 1;
    while ((u & 1) == 0) t++, u >>= 1;
    for (int i = 0; i < s; i++){
        ll a = rand() % (n - 1) + 1;
        ll x = pow_mod(a, u, n);
        for (int j = 0; j < t; j++){
            ll y = mul_mod(x, x, n);
            if (y == 1 && x != 1 && x != n - 1) return 0;
            x = y;
        }
        if (x != 1) return 0;
    }
    return 1;
}
