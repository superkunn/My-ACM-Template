const int MAXN=2e5+10;
const int INF=0x3f3f3f3f;
int a[MAXN],sa[MAXN],rk[MAXN],fir[MAXN],sec[MAXN],c[MAXN],h[MAXN];
int lg[MAXN],g[MAXN][22];
char str[MAXN];
int len;
bool cmp(int i,int j,int k){
    return sec[i]==sec[j]&&sec[i+k]==sec[j+k];
}
void sufarr(int n,int m){
    int i,p,l;
    rep(i,0,m-1)c[i]=0;
    rep(i,0,n-1)c[rk[i]=a[i]]++;
    rep(i,1,m-1)c[i]+=c[i-1];
    per(i,n-1,0)sa[--c[a[i]]]=i;
    for(l=p=1;p<n;l*=2,m=p){
        for(p=0,i=n-l;i<n;i++)sec[p++]=i;
        rep(i,0,n-1)if(sa[i]>=l)sec[p++]=sa[i]-l;
		rep(i,0,n-1)fir[i]=rk[sec[i]];
		rep(i,0,m-1)c[i]=0;
		rep(i,0,n-1)c[fir[i]]++;
		rep(i,1,m-1)c[i]+=c[i - 1];
		per(i,n-1,0)sa[--c[fir[i]]] = sec[i];
		memcpy(sec,rk,sizeof(rk));
		rk[sa[0]]=0;
		for(i=p=1;i<n;i++)rk[sa[i]]=cmp(sa[i],sa[i-1],l)?p-1:p++;
	}
}
void calh(){
	int i,j,k=0;
	rep(i,1,len)rk[sa[i]]=i;
	for(i=0;i<len;h[rk[i++]]=k)
        for (k?k--:0,j=sa[rk[i]-1];a[i+k]==a[j+k];k++);
}
void get_rmq(){
    lg[1]=0;
    for(int i=2;i<=len;++i)lg[i]=lg[i>>1]+1;
    memset(g,0x7f,sizeof(g));
    rep(i,1,len)g[i][0]=h[i];
    for(int j=1;j<=lg[len];j++){
         for(int i=1;i<=len;i++){
            g[i][j]=min(g[i][j-1],g[i+(1<<(j-1))][j-1]);
         }
    }
}
int query(int x,int y){
    int w=y-x+1;
    return min(g[x][lg[w]],g[y-(1<<lg[w])+1][lg[w]]);
}
int lcp(int x,int y){
    int l=min(rk[x],rk[y])+1;
    int r=max(rk[x],rk[y]);
    return query(l,r);
}
int main(){
    scanf("%s",str);
    len=strlen(str);
    rep(i,0,len-1)a[i]=str[i]-'a'+1;
    a[len]=0;
    sufarr(len+1,30);
    calh();
    get_rmq();
    int ans=0;
    rep(j,1,len){
        for(int i=1;i+j<=len;i+=j){
            int w=lcp(i,i+j);
            ans=max(ans,w/j+1);
            if(i>=j-w%j)ans=max(ans,lcp(i-j+w%j,i+w%j)/j+1);
        }
    }
    printf("%d",ans);
	return 0;
}
