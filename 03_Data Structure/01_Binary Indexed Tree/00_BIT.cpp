//add(pos,a) sum(r)-sum(l-1)
//add(l,a) add(r+1,-a) sum(pos)
const int MAXN=100000;
struct BIT{
    int n;
    ll c[MAXN<<1];
    void init(int _n){
        n=_n;
        rep(i,0,n)c[i]=0;
    }
    void update(int i,ll v){
        for(;i<=n;i+=i&-i)c[i]+=v;
    }
    ll query(int i){
        ll s=0;
        for(;i;i-=i&-i)s+=c[i];
        return s;
    }
    int findpos(ll v){// >=v,if can't find ,return n+1;
        ll sum=0;
        int pos=0;
        int i=1;
        for(;i<n;i<<=1);
        for(;i;i>>=1){
            if(pos+i<=n&&sum+c[pos+i]<v){
                sum+=c[pos+i];
                pos+=i;
            }
        }
        return pos+1;
    }
}bit;

