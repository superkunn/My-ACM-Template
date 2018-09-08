ll inv(ll a,ll m){
    ll x,y;
    ll d=exgcd(a,m,x,y);
    return d==1?(x+m)%m:-1;
}
ll inv(ll a,ll m){
    return pow_mod(a,m-2,m);
}
