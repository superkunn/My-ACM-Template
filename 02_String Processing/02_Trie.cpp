//CH 1601
const int MAXN=1e6+10;
int trie[MAXN][26];
int tot=1;
int cnt[MAXN];
void Insert(char* str){
    int len=strlen(str);
    int p=1;
    for(int i=0;i<len;i++){
        int ch=str[i]-'a';
        if(trie[p][ch]==0)trie[p][ch]=++tot;
        p=trie[p][ch];
    }
    cnt[p]++;
}
int query(char* str){
    int len=strlen(str);
    int p=1;
    int ans=0;
    for(int i=0;i<len;i++){
        int ch=str[i]-'a';
        if(trie[p][ch]==0)break;
        p=trie[p][ch];
        ans+=cnt[p];
    }
    return ans;
}
char ss[MAXN];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",ss);
        Insert(ss);
    }
    while(m--){
        scanf("%s",ss);
        printf("%d\n",query(ss));
    }
    return 0;
}
// max xor CH 1602
const int MAXN=2e6+10;
int trie[MAXN][2];
int tot=1;
void Insert(int x){
    int p=1;
    for(int i=30;i>=0;i--){
        int w=(x>>i)&1;
        if(trie[p][w]==0)trie[p][w]=++tot;
        p=trie[p][w];
    }
}
int query(int x){
    int p=1;
    int ans=0;
    for(int i=30;i>=0;i--){
        int w=(x>>i)&1;
        if(trie[p][w^1]!=0){
            p=trie[p][w^1];
            ans+=1<<i;
        }else{
            p=trie[p][w];
        }
    }
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    int x;
    scanf("%d",&x);
    Insert(x);
    int ans=0;
    for(int i=2;i<=n;i++){
        scanf("%d",&x);
        ans=max(ans,query(x));
        Insert(x);
    }
    printf("%d",ans);
    return 0;
}
