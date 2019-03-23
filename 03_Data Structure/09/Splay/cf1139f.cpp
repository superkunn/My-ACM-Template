//cf1139f
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define lch(x) tr[x].son[0]
#define rch(x) tr[x].son[1]
typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;
const int MAXN=2e5+10;
struct Splay{
    int tot=0,root=0;
    struct Node{
        int son[2],pre,sz,v,tsz;
        void init(int vv,int ssz){
            v=vv;
            sz=tsz=ssz;
            son[0]=son[1]=pre=0;
        }
    }tr[MAXN];
    void push_up(int x){
        tr[x].tsz=tr[x].sz+tr[lch(x)].tsz+tr[rch(x)].tsz;
    }
    void rotate(int x){
        int y=tr[x].pre;
        int z=tr[y].pre;
        int k=x==rch(y);

        tr[x].pre=z;
        tr[z].son[y==rch(z)]=x;

        tr[y].son[k]=tr[x].son[k^1];
        tr[tr[y].son[k]].pre=y;

        tr[x].son[k^1]=y;
        tr[y].pre=x;

        push_up(y);
    }
    void splay(int x,int goal){
        while(tr[x].pre!=goal){
            int y=tr[x].pre;
            int z=tr[y].pre;
            if(z!=goal){
                if((rch(y)==x)^(rch(z)==y)){
                    rotate(x);
                }else{
                    rotate(y);
                }
            }
            rotate(x);
        }
        if(!goal)root=x;
        push_up(x);
    }
    void insert_point(int v,int z){
        int p=root;
        int ff=0;
        while(p&&tr[p].v!=v){
            ff=p;
            p=tr[p].son[tr[p].v<v];
        }
        if(p){
            tr[p].sz+=z;
        }else{
            p=++tot;
            if(ff)tr[ff].son[tr[ff].v<v]=p;
            tr[p].init(v,z);
            tr[p].pre=ff;
        }
        splay(p,0);
    }
    int find_cnt(int v){
        insert_point(v,1);
        int res=tr[rch(root)].tsz;
        insert_point(v,-1);
        return res;
    }
}S[2];
int tot;
int p[MAXN],s[MAXN],b[MAXN],inc[MAXN],pref[MAXN],ans[MAXN];
struct node{
    int v,id,op;
    bool operator<(const node &rhs)const{
        if(v!=rhs.v)return v<rhs.v;
        else return op<rhs.op;
    }
}no[MAXN*3];
void add(int v,int id,int op){
    ++tot;
    no[tot]=node{v,id,op};
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n)scanf("%d",&p[i]);
    rep(i,1,n)scanf("%d",&s[i]);
    rep(i,1,n){
        scanf("%d",&b[i]);
        add(p[i],i,1);
        add(s[i],i,3);
    }
    rep(i,1,m)scanf("%d",&inc[i]);
    rep(i,1,m){
        scanf("%d",&pref[i]);
        add(inc[i],i,2);
    }
    sort(no+1,no+1+tot);
    int sum=0;
    rep(i,1,tot){
        int id=no[i].id;
        int op=no[i].op;
        if(op==1){
            sum++;
            S[0].insert_point(p[id]+b[id],1);
            S[1].insert_point(p[id]-b[id],1);
        }else if(op==2){
            ans[id]=sum-S[0].find_cnt(inc[id]+pref[id])-S[1].find_cnt(inc[id]-pref[id]);
        }else{
            sum--;
            S[0].insert_point(p[id]+b[id],-1);
            S[1].insert_point(p[id]-b[id],-1);
        }
    }
    rep(i,1,m)printf("%d ",ans[i]);
    return 0;
}
