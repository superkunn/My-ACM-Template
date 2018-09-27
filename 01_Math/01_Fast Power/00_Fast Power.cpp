typedef long long ll;
ll mul_mod(ll a,ll b,ll mod){
    ll res=0;
    for(;b;b>>=1){
        if(b&1)res=(res+a)%mod;
        a=(a<<1)%mod;
    }
    return res;
}
ll pow_mod(ll a,ll b,ll mod){//a^b
    ll res=1%mod;
    for(;b;b>>=1){
        if(b&1)res=mul_mod(res,a,mod)%mod;
        a=mul_mod(a,a,mod)%mod;
    }
    return res;
}
ll pow_mod(ll a,ll b,ll mod){//a^b
    ll res=1%mod;
    for(;b;b>>=1){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
    }
    return res;
}
