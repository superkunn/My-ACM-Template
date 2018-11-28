#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
#include    <bitset>
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
#define mp make_pair
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
const int MAXV=1e4+10;
const int MAXE=1e5+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll tot;
ll head[MAXV],level[MAXV],iter[MAXV];
struct Edge{
    ll v,cap,nxt;
    Edge(){}
    Edge(ll v,ll cap,ll nxt):v(v),cap(cap),nxt(nxt){}
}edge[MAXE<<1];
void init(){
    tot=0;
    clr(head,-1);
}
void add_edge(ll u,ll v,ll c){
    edge[tot]=Edge(v,c,head[u]);
    head[u]=tot++;
    edge[tot]=Edge(u,0,head[v]);
    head[v]=tot++;
}
void bfs(ll s){
    clr(level,-1);
    level[s]=0;
    queue<ll> que;
    que.push(s);
    while(!que.empty()){
        ll u=que.front();
        que.pop();
        for(ll i=head[u];~i;i=edge[i].nxt){
            ll v=edge[i].v;
            ll c=edge[i].cap;
            if(c>0&&level[v]<0){
                level[v]=level[u]+1;
                que.push(v);
            }
        }
    }
}
ll dfs(ll u,ll t,ll f){
    if(u==t)return f;
    for(ll &i=iter[u];~i;i=edge[i].nxt){
        ll v=edge[i].v;
        ll c=edge[i].cap;
        if(c>0&&level[u]<level[v]){
            ll d=dfs(v,t,min(f,c));
            if(d>0){
                edge[i].cap-=d;
                edge[i^1].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
ll max_flow(ll s,ll t){
    ll flow=0;
    while(1){
        bfs(s);
        if(level[t]<0)return flow;
        ll f;
        memcpy(iter,head,sizeof(head));
        while(f=dfs(s,t,INF))flow+=f;
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int s=0,t=n+m+1;
    init();
    rep(i,1,n){
        int x;
        scanf("%d",&x);
        add_edge(i,t,x);
    }
    ll sum=0;
    rep(i,1+n,n+m){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(s,i,z);
        add_edge(i,x,INF);
        add_edge(i,y,INF);
        sum+=z;
    }
    printf("%I64d",sum-max_flow(s,t));
    return 0;
}
