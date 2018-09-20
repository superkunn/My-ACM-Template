//2^n-C(0,n)...C(k-1,n)=C(k,n)+...+C(n,n)
//2017 EC A
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
const int MAXN=1e5+10;
ll cnk[MAXN],inv[MAXN];
ll pow_mod(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}
int main(){
    int T;
    scanf("%d",&T);
    int kase=0;
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        ll a=pow_mod(2,n);
        int p=MOD;
        inv[1]=1;
        for(int i=2;i<=k;i++){
            inv[i]=1LL*(p-p/i)*inv[p%i]%p;
        }
        cnk[0]=1;
        ll ans=cnk[0];
        for(int i=1;i<k;i++){
            cnk[i]=cnk[i-1]*(n-i+1)%MOD*inv[i]%MOD;
            ans+=cnk[i];
            if(ans>MOD)ans-=MOD;
        }
        ans=(a-ans+MOD)%MOD;
        printf("Case #%d: %I64d\n",++kase,ans);
    }
    return 0;
}
