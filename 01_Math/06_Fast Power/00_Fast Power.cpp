ll pow_mod(ll a,ll b,ll mod) {
    ll res=1;
    for(;b;b>>=1){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
    }
    return res;
}
//hdu 5187
ll mul_mod(ll a,ll b,ll mod){
    ll res=0;
    for(;b;b>>=1){
        if(b&1)res=(res+a)%mod;
        a=(a<<1)%mod;
    }
    return res;
}
