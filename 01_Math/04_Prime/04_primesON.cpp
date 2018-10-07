const int MAXN=2e5+10;
int v[MAXN],prime[MAXN];
int cnt;
void primes(int n){
    memset(v,0,sizeof(v));
    cnt=0;
    for(int i=2;i<=n;i++){
        if(v[i]==0){
            v[i]=i;
            prime[++cnt]=i;
        }
        for(int j=1;j<=cnt;j++){
            if(prime[j]>v[i]||prime[j]>n/i)break;
            v[i*prime[j]]=prime[j];
        }
    }
}
