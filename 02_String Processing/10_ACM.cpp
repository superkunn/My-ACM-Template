const int MAXN=1e6+10;
struct Trie{
    static const int SZ=26;
    static const int MAXL=1e6+10;
    int nxt[MAXL][SZ],f[MAXL],e[MAXL];
    int rt,tot;
    int newnode(){
        tot++;
        for(int i=0;i<SZ;i++){
            nxt[tot][i]=-1;
        }
        e[tot]=0;
        return tot;
    }
    void init(){
        tot=0;
        rt=newnode();
    }
    void add(char *buf){
        int len=strlen(buf);
        int p=rt;
        for(int i=0;i<len;i++){
            int x=buf[i]-'a';
            if(nxt[p][x]==-1)nxt[p][x]=newnode();
            p=nxt[p][x];
        }
        e[p]++;
    }
    void build(){
        queue<int> que;
        f[rt]=rt;
        for(int i=0;i<SZ;i++){
            if(nxt[rt][i]==-1){
                nxt[rt][i]=rt;
            }else{
                f[nxt[rt][i]]=rt;
                que.push(nxt[rt][i]);
            }
        }
        while(!que.empty()){
            int p=que.front();
            que.pop();
            for(int i=0;i<SZ;i++){
                if(nxt[p][i]==-1){
                    nxt[p][i]=nxt[f[p]][i];
                }else{
                    f[nxt[p][i]]=nxt[f[p]][i];;
                    que.push(nxt[p][i]);
                }
            }
        }
    }
    int query(char *buf){
        int len=strlen(buf);
        int p=rt;
        int res=0;
        for(int i=0;i<len;i++){
            int x=buf[i]-'a';
            p=nxt[p][x];
            int tmp=p;
            while(tmp!=rt){
                res+=e[tmp];
                e[tmp]=0;
                tmp=f[tmp];
            }
        }
        return res;
    }
}AC;
char s[MAXN];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        AC.init();
        while(n--){
            scanf("%s",s);
            AC.add(s);
        }
        AC.build();
        scanf("%s",s);
        printf("%d\n",AC.query(s));
    }
    return 0;
}
