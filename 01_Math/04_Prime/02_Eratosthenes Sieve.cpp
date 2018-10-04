#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=1e5+5;
int prime[MAXN];//1 base
bool is_prime[MAXN];
int sieve(int n){
    int cnt=0;
    rep(i,0,n)is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    rep(i,2,n){
        if(is_prime[i]){
            prime[++cnt]=i;
            for(int j=i;j<=n/i;j++)is_prime[i*j]=false;
        }
    }
    return cnt;
}

