//hihocoder 1015
const int MAXN=1e4+10;
const int MAXM=1e6+10;
char a[MAXN];
char b[MAXM];
int nxt[MAXN];
int f[MAXM];
int n,m;
void initkmp(){
    n=strlen(a);
    nxt[0]=-1;
    for(int i=1,j=-1;i<n;i++){
        while(j>-1&&a[i]!=a[j+1])j=nxt[j];
        if(a[i]==a[j+1])j++;
        nxt[i]=j;
    }
}
int kmp(){
    initkmp();
    int res=0;
    m=strlen(b);
    for(int i=0,j=-1;i<m;i++){
        while(j>-1&&(j==(n-1)||b[i]!=a[j+1]))j=nxt[j];
        if(b[i]==a[j+1])j++;
        f[i]=j;
        if(f[i]==n-1)res++;
    }
    return res;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s%s",&a,&b);
        printf("%d\n",kmp());
    }
    return 0;
}
   
