//cf 39 J
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
    hash_t operator + (const hash_t &x) const{
        return hash_t((hash0+x.hash0)%mod0,(hash1+x.hash1)%mod1);
    }
    ll get(){
        return 1LL*hash0*mod1+hash1;
    }
};
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=n-1;
    vector<hash_t> power(n+1);
    vector<hash_t> hsh(n+1);
    power[0]=hash_t(1,1);
    rep(i,0,n-1){
        power[i+1]=power[i]*base;
        hsh[i+1]=hsh[i]*base+s1[i];
    }
    auto get = [&](int l,int r){
        return (hsh[r]-hsh[l-1]*power[r-l+1]);
    };
    hash_t now;
    rep(i,0,m-1){
        now=now*base+s2[i];
    }
    vi ans;
    rep(i,1,n){
        hash_t cur;
        if(i==0){
            cur=get(2,n);
        }else if(i==n){
            cur=get(1,n-1);
        }else{
            cur=get(1,i-1)*power[n-i]+get(i+1,n);
        }
        if(now.get()==cur.get())ans.pb(i);
    }
    cout<<ans.size()<<endl;
    for(auto x:ans)cout<<x<<" ";
    return 0;
}


