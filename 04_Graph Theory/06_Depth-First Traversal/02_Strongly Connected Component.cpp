//cf 999 E
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5005;//点数
const int MAXM = 5005;//边数
struct Edge{
    int to,next;
} edge[MAXM];
int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];//Belong数组的值是1~scc
int Index,top;
int scc;//强连通分量的个数
bool Instack[MAXN];
void init(){
    tot = 0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v){
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void Tarjan(int u){
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    for(int i = head[u]; i != -1; i = edge[i].next){
        v = edge[i].to;
        if( !DFN[v] ){
            Tarjan(v);
            if( Low[u] > Low[v] )Low[u] = Low[v];
        }
        else if(Instack[v] && Low[u] > DFN[v])
            Low[u] = DFN[v];
    }
    if(Low[u] == DFN[u]){
        scc++;
        do{
            v = Stack[--top];
            Instack[v] = false;
            Belong[v] = scc;
        }
        while( v != u);
    }
}
void solve(int N){
    memset(DFN,0,sizeof(DFN));
    memset(Instack,0,sizeof(Instack));
    Index = scc = top = 0;
    for(int i = 1; i <= N; i++)
        if(!DFN[i])
            Tarjan(i);
}
int u[MAXM],v[MAXM],in[MAXN],vis[MAXN];
int n,m,s;
void dfs(int x){
    Belong[x]=Belong[s];
    vis[x]=true;
    for(int i=head[x];i!=-1;i=edge[i].next){
        int e=edge[i].to;
        if(!vis[e])dfs(e);
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&s);
    init();
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u[i],&v[i]);
        addedge(u[i],v[i]);
    }
    solve(n);
    dfs(s);
    int ans=0;
    for(int i=1;i<=m;i++){
        if(Belong[u[i]]!=Belong[v[i]]){
            in[Belong[v[i]]]++;
        }
    }
    set<int> ss;
    for(int i=1;i<=n;i++){
        ss.insert(Belong[i]);
    }
    set<int>::iterator it;
    for(it=ss.begin();it!=ss.end();it++){
        if(*it!=Belong[s]){
            if(in[*it]==0){
                ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
