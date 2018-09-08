typedef long long ll;
//__gcd(a,b);
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll exgcd(ll a,ll b,ll &x,ll &y){
    ll d=a;
    if(b)d=exgcd(b,a%b,y,x),y-=x*(a/b);
    else x=1,y=0;
    return d;
}
