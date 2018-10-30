const int MAXN=300010+10;
int a[MAXN],sa[MAXN],rk[MAXN],fir[MAXN],sec[MAXN],c[MAXN],h[MAXN];
char str[MAXN];
int len;
bool cmp(int i,int j,int k){
    return sec[i]==sec[j]&&sec[i+k]==sec[j+k];
}
void sufarr(int n){
    int i,p,l,m=200;
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
int main(){
	scanf("%s",str);
	len=strlen(str);
	rep(i,0,len-1)a[i]=str[i];
	a[len]=0;
	sufarr(len+1);
	calh();
	rep(i,1,len)printf("%d ",sa[i]);puts("");
	rep(i,1,len)printf("%d ",h[i]);puts("");
	return 0;
}
