//poj 3259
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int INF=1e9;
const int MAXV=500+5;
const int MAXE=2700+5;
int tot;
int head[MAXV];
struct node{
    int to,cost,next;
}edge[MAXE<<1];
int d[MAXV];
queue<int> que;
bool inq[MAXV];
int qtime[MAXV];
void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}
void add_edge(int u,int v,int x){
    edge[tot].to=v;
    edge[tot].cost=x;
    edge[tot].next=head[u];
    head[u]=tot++;
}
bool spfa(int n){
    memset(d,-1,sizeof(d));
    d[1]=0;
    while(!que.empty())que.pop();
    memset(inq,0,sizeof(inq));
    memset(qtime,0,sizeof(qtime));
    que.push(1);
    inq[1]=1;
    qtime[1]++;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        inq[u]=0;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            int w=edge[i].cost;
            if(d[v]==-1||d[u]+w<d[v]){
                d[v]=d[u]+w;
                if(!inq[v]){
                    inq[v]=1;
                    que.push(v);
                    qtime[v]++;
                    if(qtime[v]>n){
                        return false;
                    }
                }
            }
        }   
    }
    return true;
}
int main(){
    int kase;
    scanf("%d",&kase);
    while(kase--){
        init();
        int n,m,w;
        scanf("%d%d%d",&n,&m,&w);
        while(m--){
            int u,v,x;
            scanf("%d%d%d",&u,&v,&x);
            add_edge(u,v,x);
            add_edge(v,u,x);
        }
        while(w--){
            int u,v,x;
            scanf("%d%d%d",&u,&v,&x);
            add_edge(u,v,-x);
        }
        if(!spfa(n)){
            puts("YES");
        }else{
            puts("NO");
        }
    }
    return 0;
}
