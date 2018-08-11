#define key_value ch[ch[rt][1]][0]
const int MAXN=1e5;
struct Splay{
    int a[MAXN];//0 base
    int sz[MAXN],ch[MAXN][2],fa[MAXN];
    int key[MAXN],rev[MAXN];
    int rt,tot;
    int stk[MAXN],top;
    void push_up(int x){
        sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
    }
    void push_down(int x){
        if(rev[x]){
            swap(ch[x][0],ch[x][1]);
            if(ch[x][0])rev[ch[x][0]]^=1;
            if(ch[x][1])rev[ch[x][1]]^=1;
            rev[x]=0;
        }
    }
    int newnode(int p=0,int k=0){
        int x=top?stk[top--]:++tot;
        fa[x]=p;
        sz[x]=1;
        ch[x][0]=ch[x][1]=0;
        key[x]=k;
        rev[x]=0;
        return x;
    }
    int build(int l,int r,int p){
        if(l>r)return 0;
        int mid=(l+r)>>1;
        int x=newnode(p,a[mid]);
        ch[x][0]=build(l,mid-1,x);
        ch[x][1]=build(mid+1,r,x);
        push_up(x);
        return x;
    }
    void init(int n){
        tot=0,top=0;
        rt=newnode(0,-1);
        ch[rt][1]=newnode(rt,-1);
        rep(i,0,n-1)a[i]=i+1;
        key_value=build(0,n-1,ch[rt][1]);
        push_up(ch[rt][1]);
        push_up(rt);
    }
    void rotate(int x,int d){
        int y=fa[x];
        push_down(y);
        push_down(x);
        ch[y][d^1]=ch[x][d];
        fa[ch[x][d]]=y;
        if(fa[y])ch[fa[y]][ch[fa[y]][1]==y]=x;
        fa[x]=fa[y];
        ch[x][d]=y;
        fa[y]=x;
        push_up(y);
    }
    void splay(int x,int goal=0){
        push_down(x);
        while(fa[x]!=goal){
            if(fa[fa[x]]==goal){
                rotate(x,ch[fa[x]][0]==x);
            }else{
                int y=fa[x];
                int d=ch[fa[y]][0]==y;
                ch[y][d]==x?rotate(x,d^1):rotate(y,d);
                rotate(x,d);
            }
        }
        push_up(x);
        if(goal==0)rt=x;
    }
    int kth(int r,int k){
        push_down(r);
        int t=sz[ch[r][0]]+1;
        if(t==k)return r;
        return t>k?kth(ch[r][0],k):kth(ch[r][1],k-t);
    }
    void select(int l,int r){
        splay(kth(rt,1),0);
        splay(kth(ch[rt][1],r-l+2),rt);
    }
};
