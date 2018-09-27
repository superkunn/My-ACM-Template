typedef long long ll;
void add(ll &a,ll b,ll mod){
    a+=b;
    a%=mod;
}
ll mul_mod(ll a,ll b,ll mod){
    ll res=0;
    while(b){
        if(b&1)add(res,a,mod);
        add(a,a,mod);
        b>>=1;
    }
    return res;
}
ll pow_mod(ll a,ll b,ll mod){
    ll res=1%mod;
    while(b){
        if(b&1)res=mul_mod(res,a,mod);
        a=mul_mod(a,a,mod);
        b>>=1;
    }
    return res;
}
