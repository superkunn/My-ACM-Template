//cf 1056E
const int base=2333;
const int mod0=1e9+7;
const int mod1=1e9+9;
struct hash_t{
    int hash0,hash1;
    hash_t(int hash0=0,int hash1=0):hash0(hash0),hash1(hash1){}
    hash_t operator + (const int &x) const{
        return hash_t((hash0+x)%mod0,(hash1+x)%mod1);
    }
    hash_t operator * (const int &x) const{
        return hash_t(1LL*hash0*x%mod0,1LL*hash1*x%mod1);
    }
    hash_t operator - (const hash_t &x) const{
        return hash_t((hash0+mod0-x.hash0)%mod0,(hash1+mod1-x.hash1)%mod1);
    }
    hash_t operator * (const hash_t &x) const{
        return hash_t(1LL*hash0*x.hash0%mod0,1LL*hash1*x.hash1%mod1);
    }
    ll get(){
        return 1LL*hash0*mod1+hash1;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s,t;
    cin>>s>>t;
    int n=s.length();
    int m=t.length();
    if(m<n){
        cout<<0<<endl;
        return 0;
    }
    vector<hash_t> power(m+1);
    vector<hash_t> hsh(m+1);
    power[0]=hash_t(1,1);
    rep(i,0,m-1){
        power[i+1]=power[i]*base;
        hsh[i+1]=hsh[i]*base+t[i];
    }
    // get hsh [l,r)
    auto get = [&](int l,int r){
        return (hsh[r]-hsh[l]*power[r-l]).get();
    };
    int cnt0=0;
    int cnt1=0;
    for(auto c:s){
        if(c=='0')cnt0++;
        else cnt1++;
    }
    int ans=0;
    if(cnt0>cnt1){
        rep(i,1,m){
            int r0=i;
            int r1;
            ll w=1LL*r0*cnt0;
            if(w>=m)break;
            w=m-w;
            if(w%cnt1!=0)continue;
            r1=w/cnt1;
            int now=0;
            ll hsh0=-1;
            ll hsh1=-1;
            bool f=true;
            rep(j,0,n-1){
                if(!f)break;
                if(s[j]=='0'){
                    if(hsh0==-1){
                        hsh0=get(now,now+r0);
                        now+=r0;
                    }else{
                        if(now+r0>m||hsh0!=get(now,now+r0))f=false;
                        now+=r0;
                    }
                }else{
                    if(hsh1==-1){
                        hsh1=get(now,now+r1);
                        now+=r1;
                    }else{
                        if(now+r1>m||hsh1!=get(now,now+r1))f=false;
                        now+=r1;
                    }
                }
            }
            if(f&&hsh0!=hsh1)ans++;
        }
    }else{
        rep(i,1,m){
            int r1=i;
            int r0;
            ll w=1LL*r1*cnt1;
            if(w>=m)break;
            w=m-w;
            if(w%cnt0!=0)continue;
            r0=w/cnt0;
            int now=0;
            ll hsh0=-1;
            ll hsh1=-1;
            bool f=true;
            rep(j,0,n-1){
                if(!f)break;
                if(s[j]=='0'){
                    if(hsh0==-1){
                        hsh0=get(now,now+r0);
                        now+=r0;
                    }else{
                        if(now+r0>m||hsh0!=get(now,now+r0))f=false;
                        now+=r0;
                    }
                }else{
                    if(hsh1==-1){
                        hsh1=get(now,now+r1);
                        now+=r1;
                    }else{
                        if(now+r1>m||hsh1!=get(now,now+r1))f=false;
                        now+=r1;
                    }
                }
            }
            if(f&&hsh0!=hsh1)ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

