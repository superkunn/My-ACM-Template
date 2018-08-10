//add(pos,a) sum(r)-sum(l-1)
//add(l,a) add(r+1,-a) sum(pos)
const int MAXN=100000;
struct BIT{
    int n,c[MAXN<<1];
    void init(int _n){n=_n;for(int i=0;i<=n;i++)c[i]=0;}
    void add(int i,int v){for(;i<=n;i+=i&-i)c[i]+=v;}
    int sum(int i){int s=0;for(;i>0;i-=i&-i)s+=c[i];return s;}
}bit;


