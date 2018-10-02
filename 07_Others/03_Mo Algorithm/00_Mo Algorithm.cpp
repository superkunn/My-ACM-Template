//hdu 6333
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
const int MOD=1e9+7;
int block;
struct node{
    int l,r,id;
}no[MAXN];
bool cmp(node x,node y){
    if(x.l/block==y.l/block)return x.r<y.r;
    else return x.l/block<y.l/block;
}
int ans[MAXN];
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
int main(){
    int n=100000;
    fact[0]=1;
    for(int i=1;i<=n;i++){
        fact[i]=1LL*fact[i-1]*i%MOD;
    }
    invfact[n]=pow_mod(fact[n],MOD-2);
    for(int i=n;i>=1;i--){
        invfact[i-1]=1LL*invfact[i]*i%MOD;
    }
    int q;
    scanf("%d",&q);
    block=(int)sqrt(100000);
    for(int i=1;i<=q;i++){
        scanf("%d%d",&no[i].r,&no[i].l);
        no[i].id=i;
    }
    sort(no+1,no+1+q,cmp);
    int L=1,R=1;
    ll now=2;
    int inv2=pow_mod(2,MOD-2);
    for(int i=1;i<=q;i++){
        while(R<no[i].r){
            now=(now*2-fun(R,L)+MOD)%MOD;
            R++;
        }
        while(L>no[i].l){
            now=(now-fun(R,L)+MOD)%MOD;
            L--;
        }
        while(R>no[i].r){
            R--;
            now+=fun(R,L);
            now%=MOD;
            now=now*inv2%MOD;
        }
        while(L<no[i].l){
            L++;
            now=(now+fun(R,L))%MOD;
        }
        ans[no[i].id]=now;
    }
    for(int i=1;i<=q;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
