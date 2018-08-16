//hihocoder 1014
const int maxnode=2600000+10;
const int sigma_size=26;
struct Trie{
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int sz;
    void init(){sz=0;clr(ch[0],0);}
    int idx(char c){return c-'a';}
    void insert(char *s){
        int u=0,n=strlen(s);
        rep(i,0,n-1){
            int x=idx(s[i]);
            if(!ch[u][x]){
                ++sz;
                clr(ch[sz],0);
                val[sz]=0;
                ch[u][x]=sz;
            }
            u=ch[u][x];
            val[u]++;
        }
    }
    int query(char *s){
        int u=0,n=strlen(s),res=0;
        rep(i,0,n-1){
            int x=idx(s[i]);
            if(!ch[u][x])break;
            u=ch[u][x];
            if(i==n-1)res=val[u];
        }
        return res;
    }
}trie;
char s[30];
int work(){
    trie.init();
    int n,m;
    scanf("%d",&n);
    while(n--){
        scanf("%s",s);
        trie.insert(s);
    }
    scanf("%d",&m);
    while(m--){
        scanf("%s",s);
        printf("%d\n",trie.query(s));
    }
    return 0;
}
