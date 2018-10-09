#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
#include     <stack>
#include     <queue>
#include     <cmath>
#include       <set>
#include       <map>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define clr(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
const int SIZE=1e5+10;
struct Treap{
    int l,r;
    int val,dat;
    int cnt,sz;
}a[SIZE];
int tot,root,n,INF=0x7fffffff;
int New(int val){
    a[++tot].val=val;
    a[tot].dat=rand();
    a[tot].cnt=a[tot].sz=1;
    return tot;
}
void Update(int p){
    a[p].sz=a[a[p].l].sz+a[a[p].r].sz+a[p].cnt;
}
void Build(){
    New(-INF);
    New(INF);
    root=1;
    a[1].r=2;
    Update(root);
}
int GetRankByVal(int p,int val){
    if(p==0)return 0;
    if(val==a[p].val)return a[a[p].l].sz+1;
    if(val<a[p].val)return GetRankByVal(a[p].l,val);
    return GetRankByVal(a[p].r,val)+a[a[p].l].sz+a[p].cnt;
}
int GetValByRank(int p,int rk){
    if(p==0)return INF;
    if(a[a[p].l].sz>=rk)return GetValByRank(a[p].l,rk);
    if(a[a[p].l].sz+a[p].cnt>=rk)return a[p].val;
    return GetValByRank(a[p].r,rk-a[a[p].l].sz-a[p].cnt);
}
void zig(int &p){
    int q=a[p].l;
    a[p].l=a[q].r;
    a[q].r=p;
    p=q;
    Update(a[p].r);
    Update(p);
}
void zag(int &p){
    int q=a[p].r;
    a[p].r=a[q].l;
    a[q].l=p;
    p=q;
    Update(a[p].l);
    Update(p);
}
void Insert(int &p,int val){
    if(p==0){
        p=New(val);
        return;
    }
    if(val==a[p].val){
        a[p].cnt++;
        Update(p);
        return;
    }
    if(val<a[p].val){
        Insert(a[p].l,val);
        if(a[p].dat<a[a[p].l].dat)zig(p);
    }else{
        Insert(a[p].r,val);
        if(a[p].dat<a[a[p].r].dat)zag(p);
    }
    Update(p);
}
int GetPre(int val){
    int ans=1;
    int p=root;
    while(p){
        if(val==a[p].val){
            if(a[p].l>0){
                p=a[p].l;
                while(a[p].r>0)p=a[p].r;
                ans=p;
            }
            break;
        }
        if(a[p].val<val&&a[p].val>a[ans].val)ans=p;
        p=val<a[p].val?a[p].l:a[p].r;
    }
    return a[ans].val;
}
int GetNext(int val){
    int ans=2;
    int p=root;
    while(p){
        if(val==a[p].val){
            if(a[p].r>0){
                p=a[p].r;
                while(a[p].l>0)p=a[p].l;
                ans=p;
            }
            break;
        }
        if(a[p].val>val&&a[p].val<a[ans].val)ans=p;
        p=val<a[p].val?a[p].l:a[p].r;
    }
    return a[ans].val;
}
void Remove(int &p,int val){
    if(p==0)return;
    if(val==a[p].val){
        if(a[p].cnt>1){
            a[p].cnt--;
            Update(p);
            return;
        }
        if(a[p].l||a[p].r){
            if(a[p].r==0||a[a[p].l].dat>a[a[p].r].dat){
                zig(p);
                Remove(a[p].r,val);
            }else{
                zag(p);
                Remove(a[p].l,val);
            }
            Update(p);
        }else{
            p=0;
        }
        return;
    }
    val<a[p].val?Remove(a[p].l,val):Remove(a[p].r,val);
    Update(p);
}
int main(){
    Build();
    int n;
    scanf("%d",&n);
    while(n--){
        int op,x;
        scanf("%d%d",&op,&x);
        switch(op){
        case 1:
            Insert(root,x);
            break;
        case 2:
            Remove(root,x);
            break;
        case 3:
            printf("%d\n",GetRankByVal(root,x)-1);
            break;
        case 4:
            printf("%d\n",GetValByRank(root,x+1));
            break;
        case 5:
            printf("%d\n",GetPre(x));
            break;
        case 6:
            printf("%d\n",GetNext(x));
            break;
        }
    }
    return 0;
}
