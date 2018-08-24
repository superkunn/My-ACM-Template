__gcd(a,b);

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

//ax+by=1 gcd(a,b)=1
// ll x,y;
//exgcd(3,5,x,y);
//x=2,y=-1;
ll exgcd(ll a, ll b, ll &x, ll &y){
    ll d = a;
    if (b){
        d = exgcd(b, a % b, y, x);
        y -= x * (a / b);
    } else{
        x=1;y=0;
    }
    return d;
}
