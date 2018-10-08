//cf 616 E
const int MOD=1e9+7;
int main(){
    ll n,k,ans;
    scanf("%lld%lld",&k,&n);
    ans=n%MOD*(k%MOD);
    ans%=MOD;
    ll inv2=MOD-MOD/2;
    for(ll x=1,gx;x<=n;x=gx+1){
        gx=k/x?min(k/(k/x),n):n;
        ans-=((k/x)%MOD*((x+gx)%MOD)%MOD*((gx-x+1)%MOD)%MOD*inv2)%MOD;
        if(ans<0)ans+=MOD;
    }
    printf("%lld",ans);
    return 0;
}
