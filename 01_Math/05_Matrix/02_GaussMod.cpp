const int MOD=1e6+3;
ll pow_mod(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}
ll m[15][15];
void gauss(int n){
    rep(i,0,n-1){
        ll b=pow_mod(m[i][i],MOD-2);
        rep(j,i,n){
            m[i][j]=m[i][j]*b%MOD;
        }
        rep(j,0,n-1){
            if(j!=i){
                ll c=m[j][i];
                rep(k,0,n){
                    m[j][k]=(m[j][k]-m[i][k]*c%MOD+MOD)%MOD;
                }
            }
        }
    }
}
ll fun(int x){
    ll res=0;
    ll now=1;
    rep(i,0,10){
        res+=now*m[i][11]%MOD;
        if(res>=MOD){
            res-=MOD;
        }
        now=now*x%MOD;
    }
    return res;
}
int main(){
    rep(i,0,10){
        rep(j,0,10){
            m[i][j]=pow_mod(i,j);
        }
    }
    rep(i,0,10){
        printf("? %d\n",i);
        fflush(stdout);
        scanf("%lld",&m[i][11]);
    }
    gauss(11);
    rep(i,0,MOD-1){
        if(fun(i)==0){
            printf("! %d",i);
            fflush(stdout);
            return 0;
        }
    }
    printf("! -1");
    fflush(stdout);
    return 0;
}
/*


*/
