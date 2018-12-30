// CF 1096G Lucky Tickets
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
typedef long long ll;
const ll MOD=998244353;
const int MAXN=5e6+10;
const ll g=3;
ll fp(ll a,ll b){
    if(b<0){
        a=fp(a,MOD-2);
        b=-b;
    }
    ll res=1;
    while(b){
        if(b&1)res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}
void change(ll y[],int len){
    int i,j,k;
    for(i=1,j=len/2;i<len-1;i++){
        if(i<j)swap(y[i],y[j]);
        k=len/2;
        while(j>=k){
            j-=k;
            k/=2;
        }
        if(j<k)j+=k;
    }
}
void ntt(ll y[],int len,int on){
    change(y,len);
    for(int h=2;h<=len;h<<=1){
        ll wn=fp(g,-on*(MOD-1)/h);
        for(int j=0;j<len;j+=h){
            ll w=1;
            for(int k=j;k<j+h/2;k++){
                ll u=y[k];
                ll t=w*y[k+h/2]%MOD;
                y[k]=(u+t)%MOD;
                y[k+h/2]=(u-t+MOD)%MOD;
                w=w*wn%MOD;
            }
        }
    }
    if(on==-1){
        ll t=fp(len,-1);
        rep(i,0,len-1){
            y[i]=y[i]*t%MOD;
        }
    }
}
ll x[MAXN];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    rep(i,1,k){
        int v;
        scanf("%d",&v);
        x[v]=1;
    }
    int len=1;
    for(;len<10*n;len<<=1);
    ntt(x,len,1);
    rep(i,0,len-1){
        x[i]=fp(x[i],n/2);
    }
    ntt(x,len,-1);
    ll res=0;
    rep(i,0,len-1){
        res=(res+x[i]*x[i]%MOD)%MOD;
    }
    printf("%I64d",res);
    return 0;
}
